//
// Created by thomas on 1/08/24.
//

#include "World.h"

World::World(shared_ptr<ConcreteFactory> factory, int level) {
    createEntities(factory, level);
}

void World::createEntities(shared_ptr<ConcreteFactory> factory, int level) {
    addEntity(factory->createPacMan(-1, -0.9));

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
    // get the pacman entity
    shared_ptr<PacManModel> pacMan;
    for (auto entity : entities) {
        if (entity->getType() == PacMan) {
            pacMan = dynamic_pointer_cast<PacManModel>(entity);
        }
    }
    pacMan->setDirection(d);
    //if (!movePacMan(pacMan, d)){
    //
    //}
    //else{
    //    movePacMan(pacMan, currentDirection);
    //}
    for (auto entity : entities) {
        entity->update();
    }
}

bool World::movePacMan(shared_ptr<PacManModel> pacman, Direction d) {
    if (d == Up){
        if (currentDirection == Up or currentDirection == Down){

        }
    }
    return false;
}
