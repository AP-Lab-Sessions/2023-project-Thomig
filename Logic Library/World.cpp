//
// Created by thomas on 1/08/24.
//

#include "World.h"

World::World(shared_ptr<ConcreteFactory> f) {
    factory = f;
    createEntities();
}

void World::createEntities() {
    int level = Stats::getInstance()->getLevel();
    ifstream file("../Levels/Level" + to_string(level) + ".txt");
    vector<string> lines;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }

    double width = -1;
    double height = -1;
    for (const auto &line: lines) {
        for (const auto &ch: line) {
            if (ch == 'W') {
                addEntity(factory->createWall(width, height));
            } else if (ch == 'P') {
                addEntity(factory->createPacMan(width, height));
                pacman = static_pointer_cast<PacManModel>(entities.back());
            } else if (ch == 'F') {
                addEntity(factory->createFruit(width, height));
            } else if (ch == 'C') {
                addEntity(factory->createCoin(width, height));
            } else if (ch == 'G') {
                addEntity(factory->createGhost(width, height));
                ghosts.push_back(static_pointer_cast<GhostModel>(entities.back()));
            }
            width += 0.1;
        }
        width = -1;
        height += 0.1;
    }
    // if more than 4 ghosts error
    if (ghosts.size() > 4) {
        throw runtime_error("Too many ghosts");
    } else {
        vector<Color> colors = {Red, Pink, Blue, Orange};
        for (int i = 0; i < ghosts.size(); i++) {
            ghosts[i]->setColor(colors[i]);
        }
    }
    StopWatch::getInstance()->start();
    StopWatch::getInstance()->update();
}

void World::addEntity(shared_ptr<EntityModel> entity) {
    entities.push_back(entity);
}

void World::removeEntity(shared_ptr<EntityModel> entity) {
    entities.erase(remove(entities.begin(), entities.end(), entity), entities.end());
}

void World::update(Direction newDirection) {
    shared_ptr<StopWatch> stopWatch = StopWatch::getInstance();
    shared_ptr<Stats> stats = Stats::getInstance();
    if (stats->getResetWorldClock()) {
        // Reset stopwatch after pause
        stopWatch->reset();
        stats->switchResetWorldClock();
    }
    double deltaTime = stopWatch->getDeltaTime().count();
    stats->setFps(1000000 / deltaTime);
    worldTime += deltaTime / 1000000.0;

    // Calculate distance to move based on time
    double distance = deltaTime * 0.0000002;

    stopWatch->update();

    // Coins
    double randomNumber = Random::getInstance()->getRandomNumber();
    coinPickupInterval += deltaTime / 500000.0;
    if (coinPickupInterval > 9) {
        coinPickupInterval = 9;
    }
    // Decrease score over time
    if (randomNumber < 0.0002) {
        stats->decreaseScore();
    }

    // Move pacman
    if (!pacman->isSlipped()) {
        if (movePacMan(newDirection, distance)) {
            currentDirection = newDirection;
            pacman->setDirection(newDirection);
        } else {
            movePacMan(currentDirection, distance);
        }
    }
    pacman->decreaseSlipped();

    // Move ghosts
    int movingGhosts = 2;
    if (worldTime >= 5) {
        movingGhosts = 3;
    }
    if (worldTime >= 10) {
        movingGhosts = 4;
    }
    for (int i = 0; i < movingGhosts; i++) {
        if (ghosts[i]->changeDirection()) {
            moveGhosts(ghosts[i], distance);
        } else {
            moveGhost(ghosts[i], ghosts[i]->getDirection(), distance);
        }
    }

    // Update sprite timers
    spriteUpdateTime += deltaTime / 1000000.0;
    if (spriteUpdateTime >= 0.1) {
        pacman->incrementSpriteTimer();
        for (auto ghost: ghosts) {
            ghost->incrementSpriteTimer();
        }
        spriteUpdateTime = 0;
    }

    // Add random banana
    if (randomNumber <= 0.00003 and bananaTimer == 0) {
        double randomIndex = lround(Random::getInstance()->getRandomNumber() * bananaPositions.size() - 1);
        if (randomIndex > 0 and randomIndex < bananaPositions.size() - 1) {
            factory = make_shared<ConcreteFactory>();
            addEntity(factory->createBanana(bananaPositions[randomIndex].first, bananaPositions[randomIndex].second));
            bananaTimer = 50000;
        }
    } else if (bananaTimer != 0) {
        bananaTimer--;
    }

    // Check if dead
    pacman->getHitBox();
    for (auto ghost: ghosts) {
        if (areRectanglesIntersecting(pacman->getHitBox(), ghost->getHitBox())) {
            if (ghost->getState() == Fear) {
                ghost->resetPosition();
                stats->increaseScore(200);
            } else {
                stats->decreaseLives();
                pacman->resetPosition();
                currentDirection = Left;
                for (auto g: ghosts) {
                    g->resetPosition();
                }
            }
        }
    }

    // Check if won
    if (levelCompleted()) {
        entities.clear();
        stats->increaseLevel();
        stats->increaseDifficulty();
        stats->changeLevelCompleted();
        stats->increaseScore(250);
        return;
    }

    // Update all entities
    for (auto entity: entities) {
        entity->update();
    }
}

bool World::movePacMan(Direction newDirection, double distance) {  // move pacman if no collision
    double x = pacman->getPosition().first;
    double y = pacman->getPosition().second;
    switch (newDirection) {
        case Up:
            y -= 0.04;
            break;
        case Down:
            y += 0.04;
            break;
        case Left:
            x -= 0.04;
            break;
        case Right:
            x += 0.04;
            break;
    }
    Rectangle pacmanHitBox = pacman->getHitBox();
    pacmanHitBox.x = x + 1;
    pacmanHitBox.y = y + 1;

    for (auto entity: entities) {
        Rectangle hitBox = entity->getHitBox();
        if (areRectanglesIntersecting(pacmanHitBox, hitBox)) {
            if (entity->getType() == Wall) {
                return false;
            } else if (entity->getType() == Coin) {
                bananaPositions.push_back(entity->getPosition());
                removeEntity(entity);
                shared_ptr<Stats> stats = Stats::getInstance();
                stats->increaseScore(10 - coinPickupInterval);
                // Picking up coins faster is more score
                if (coinPickupInterval > 2) {
                    coinPickupInterval -= 2;
                }
                return true;
            } else if (entity->getType() == Fruit) {
                removeEntity(entity);
                shared_ptr<Stats> stats = Stats::getInstance();
                stats->increaseScore(50);
                for (auto ghost: ghosts) {
                    ghost->enableFear();
                }
                return true;
            } else if (entity->getType() == Banana) {
                removeEntity(entity);
                shared_ptr<Stats> stats = Stats::getInstance();
                pacman->slip();
                bananaTimer = 0;
                return true;
            }
        }
    }
    x = pacman->getPosition().first;
    y = pacman->getPosition().second;
    switch (newDirection) {
        case Up:
            y -= distance;
            break;
        case Down:
            y += distance;
            break;
        case Left:
            x -= distance;
            break;
        case Right:
            x += distance;
            break;
    }
    pacman->setPosition(x, y);
    return true;
}

void World::moveGhosts(shared_ptr<GhostModel> ghost, double distance) {
    vector<Direction> possibleDirections;
    vector<Direction> imPossibleDirections;
    switch (ghost->getDirection()) {
        case Up:
            possibleDirections = {Up, Left, Right};
            break;
        case Down:
            possibleDirections = {Down, Left, Right};
            break;
        case Left:
            possibleDirections = {Up, Down, Left};
            break;
        case Right:
            possibleDirections = {Up, Down, Right};
            break;
    }

    for (auto direction: possibleDirections) {
        double x = ghost->getPosition().first;
        double y = ghost->getPosition().second;
        switch (direction) {
            case Up:
                y -= 0.04;
                break;
            case Down:
                y += 0.04;
                break;
            case Left:
                x -= 0.04;
                break;
            case Right:
                x += 0.04;
                break;
        }
        Rectangle ghostHitBox = ghost->getHitBox1();
        ghostHitBox.x = x + 1;
        ghostHitBox.y = y + 1;

        for (auto entity: entities) {
            if (entity->getType() == Wall) {
                Rectangle wallHitBox = entity->getHitBox();
                if (areRectanglesIntersecting(ghostHitBox, wallHitBox)) {
                    imPossibleDirections.push_back(direction);
                }
            }
        }
    }

    // Remove impossible directions from possible directions
    for (auto direction: imPossibleDirections) {
        possibleDirections.erase(remove(possibleDirections.begin(), possibleDirections.end(), direction),
                                 possibleDirections.end());
    }

    if (possibleDirections.empty()) {
        switch (ghost->getDirection()) {
            case Up:
                moveGhost(ghost, Down, distance * 100);
                ghost->setDirection(Down);
                return;
            case Down:
                moveGhost(ghost, Up, distance * 100);
                ghost->setDirection(Up);
                return;
            case Left:
                moveGhost(ghost, Right, distance * 100);
                ghost->setDirection(Right);
                return;
            case Right:
                moveGhost(ghost, Left, distance * 100);
                ghost->setDirection(Left);
                return;
        }
    } else if (possibleDirections.size() == 1) {
        moveGhost(ghost, possibleDirections[0], distance);
    } else {
        // Setup mode
        if (ghost->getState() == Setup) {
            if (find(possibleDirections.begin(), possibleDirections.end(), Up) != possibleDirections.end()) {
                moveGhost(ghost, Up, distance);
            }
        }
        // Random direction
        double randomNumber = Random::getInstance()->getRandomNumber();
        if (randomNumber <= 0.5) {
            int index = 0;
            double randomIndex = Random::getInstance()->getRandomNumber();
            if (possibleDirections.size() == 2) {
                if (randomIndex < 0.5) {
                    index = 0;
                } else {
                    index = 1;
                }
            } else {
                if (randomIndex < 0.33) {
                    index = 0;
                } else if (randomIndex < 0.66) {
                    index = 1;
                } else {
                    index = 2;
                }
            }

            ghost->resetChangeDirectionTimer();
            moveGhost(ghost, possibleDirections[index], distance);
        } else {
            // Manhattan distance
            vector<double> manhattanDistances;
            for (auto direction: possibleDirections) {
                manhattanDistances.push_back(calculateManhattanDistance(ghost, direction, distance));
            }
            int index = 0;
            if (ghost->getState() == Fear) {
                index = max_element(manhattanDistances.begin(), manhattanDistances.end())
                        - manhattanDistances.begin();
            } else {
                index = min_element(manhattanDistances.begin(), manhattanDistances.end())
                        - manhattanDistances.begin();
            }
            ghost->resetChangeDirectionTimer();
            moveGhost(ghost, possibleDirections[index], distance);
        }
    }
}

void World::moveGhost(shared_ptr<GhostModel> ghost, Direction d, double distance) {
    double x = ghost->getPosition().first;
    double y = ghost->getPosition().second;
    switch (d) {
        case Up:
            y -= distance * ghost->getSpeed();
            break;
        case Down:
            y += distance * ghost->getSpeed();
            break;
        case Left:
            x -= distance * ghost->getSpeed();
            break;
        case Right:
            x += distance * ghost->getSpeed();
            break;
    }
    ghost->setPosition(x, y);
    ghost->updateChangeDirectionTimer();
    ghost->setDirection(d);
}

bool World::areRectanglesIntersecting(const Rectangle &rectA, const Rectangle &rectB) {
    return (rectA.x < rectB.x + rectB.width &&
            rectA.x + rectA.width > rectB.x &&
            rectA.y < rectB.y + rectB.height &&
            rectA.y + rectA.height > rectB.y);
}

double World::calculateManhattanDistance(shared_ptr<GhostModel> ghost, Direction d, double distance) {
    double x = ghost->getPosition().first;
    double y = ghost->getPosition().second;
    switch (d) {
        case Up:
            y -= distance;
            break;
        case Down:
            y += distance;
            break;
        case Left:
            x -= distance;
            break;
        case Right:
            x += distance;
            break;
    }
    double pacmanX = pacman->getPosition().first + 1;
    double pacmanY = pacman->getPosition().second + 1;
    double manhattanDistance = x - pacmanX + y - pacmanY;
    return manhattanDistance;
}

bool World::levelCompleted() {
    for (auto entity: entities) {
        if (entity->getType() == Coin or entity->getType() == Fruit) {
            return false;
        }
    }
    return true;
}
