//
// Created by thomas on 1/08/24.
//

#include "World.h"

World::World(shared_ptr<ConcreteFactory> factory, int level) {
    createEntities(factory, level);
}

void World::createEntities(shared_ptr<ConcreteFactory> factory, int level) {
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
    for (const auto& line : lines) {
        for (const auto& ch : line) {
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
    }
    else{
        vector<Color> colors = {Red, Pink, Blue, Orange};
        for (int i = 0; i < ghosts.size(); i++) {
            ghosts[i]->setColor(colors[i]);
        }
    }
    StopWatch::getInstance()->start();
}

void World::addEntity(shared_ptr<EntityModel> entity) {
    entities.push_back(entity);
}

void World::removeEntity(shared_ptr<EntityModel> entity) {
    entities.erase(remove(entities.begin(), entities.end(), entity), entities.end());
}

vector<shared_ptr<EntityModel>> World::getEntities() {
    return entities;
}

void World::update(Direction newDirection) {
    shared_ptr<StopWatch> stopWatch = StopWatch::getInstance();
    double deltaTime = stopWatch->getDeltaTime().count();
    worldTime += deltaTime/1000000.0;

    // Calculate distance to move based on time
    double distance = deltaTime * 0.0000002;
    stopWatch->update();

    // Move pacman
    if (movePacMan(newDirection, distance)) {
        currentDirection = newDirection;
        pacman->setDirection(newDirection);
    }
    else{
        movePacMan(currentDirection, distance);
    }

    // Move ghosts
    for (auto ghost : ghosts) {
        if (ghost->changeDirection()) {
            moveGhosts(ghost, distance);
        }
        else {
            moveGhost(ghost, ghost->getDirection(), distance);
        }
    }

    // Update sprite timers
    spriteUpdateTime += deltaTime/1000000.0;
    if (spriteUpdateTime >= 0.1) {
        pacman->incrementSpriteTimer();
        for (auto ghost : ghosts) {
            ghost->incrementSpriteTimer();
        }
        spriteUpdateTime = 0;
    }

    // Update all entities
    for (auto entity : entities) {
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
    pacmanHitBox.x = x+1;
    pacmanHitBox.y = y+1;

    for (auto entity : entities) {
        if (entity->getType() == Wall) {
            Rectangle wallHitBox = entity->getHitBox();
            if (areRectanglesIntersecting(pacmanHitBox, wallHitBox)) {
                return false;
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

    for (auto direction : possibleDirections) {
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
        Rectangle ghostHitBox = ghost->getHitBox();
        ghostHitBox.x = x+1;
        ghostHitBox.y = y+1;

        for (auto entity : entities) {
            if (entity->getType() == Wall) {
                Rectangle wallHitBox = entity->getHitBox();
                if (areRectanglesIntersecting(ghostHitBox, wallHitBox)) {
                    imPossibleDirections.push_back(direction);
                }
            }
        }
    }
    
    // Remove impossible directions from possible directions
    for (auto direction : imPossibleDirections) {
        possibleDirections.erase(remove(possibleDirections.begin(), possibleDirections.end(), direction), possibleDirections.end());
    }

    if (possibleDirections.empty()) {
        cout << "Ghost is stuck" << endl;
    }
    else if (possibleDirections.size() == 1) {
        moveGhost(ghost, possibleDirections[0], distance);
    }
    else {
        double randomNumber = Random::getInstance()->getRandomNumber();
        if (randomNumber <= 1){
            int index = 0;
            double randomIndex = Random::getInstance()->getRandomNumber();
            if (possibleDirections.size() == 2) {
                if (randomIndex < 0.5) {
                    index = 0;
                }
                else {
                    index = 1;
                }
            }
            else {
                if (randomIndex < 0.33) {
                    index = 0;
                }
                else if (randomIndex < 0.66) {
                    index = 1;
                }
                else {
                    index = 2;
                }
            }

            ghost->resetChangeDirectionTimer();
            moveGhost(ghost, possibleDirections[index], distance);
        } else {
            // Manhattan distance
        }
    }
}

void World::moveGhost(shared_ptr<GhostModel> ghost, Direction d, double distance) {
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

double World::calculateManhattanDistance(shared_ptr<GhostModel> ghost, double distance) {
    double ghostx = ghost->getPosition().first+1;
    double ghostY = ghost->getPosition().second+1;
    double pacmanX = pacman->getPosition().first+1;
    double pacmanY = pacman->getPosition().second+1;
    double manhattanDistance = ghostx - pacmanX + ghostY - pacmanY;
    return manhattanDistance;
}

