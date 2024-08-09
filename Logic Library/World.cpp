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
            }
            width += 0.1;
        }
        width = -1;
        height += 0.1;
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

void World::update(Direction d) {
    shared_ptr<StopWatch> stopWatch = StopWatch::getInstance();
    worldTime += stopWatch->getDeltaTime().count();
    double distance = stopWatch->getDeltaTime().count() * 0.005;
    stopWatch->update();

    if (movePacMan(d, 0.0001)) {
        /*
        if (currentDirection != d){
            // Make sure pacman is in the middle of the lane
            if (d == Up || d == Down){
                double x = lround(pacman->getPosition().first*10)/10.0;
                pacman->setPosition(x, pacman->getPosition().second);
            }
            else if (d == Left || d == Right){
                double y = lround(pacman->getPosition().second*10)/10.0;
                pacman->setPosition(pacman->getPosition().first, y);
            }
            else{
                double x = lround(pacman->getPosition().first*10)/10.0;
                double y = lround(pacman->getPosition().second*10)/10.0;
                pacman->setPosition(x, y);
            }
        }
        */
        currentDirection = d;
    }
    else{
        movePacMan(currentDirection, 0.0001);
    }
    //pacman->setPosition(pacman->getPosition().first-0.00005, pacman->getPosition().second);
    //cout << pacman->getPosition().first << " " << pacman->getPosition().second << endl;

    for (auto entity : entities) {
        entity->update();
    }
}

bool World::movePacMan(Direction d, double distance) {  // move pacman if no collision
    double x = pacman->getPosition().first;
    double y = pacman->getPosition().second;
    switch (d) {
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
    pacman->setPosition(x, y);
    return true;
}

bool World::areRectanglesIntersecting(const Rectangle &rectA, const Rectangle &rectB) {
    return (rectA.x < rectB.x + rectB.width &&
            rectA.x + rectA.width > rectB.x &&
            rectA.y < rectB.y + rectB.height &&
            rectA.y + rectA.height > rectB.y);
}
