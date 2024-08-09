
//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_WORLD_H
#define PROJECTAP_WORLD_H

#include <vector>
#include "algorithm"
#include "memory"
#include "fstream"
#include "string"
#include "cmath"
#include "EntityModel.h"
#include "../Game Representation/ConcreteFactory.h"
#include "StopWatch.h"

using namespace std;

// Entity Controller
class World {
public:
    World() = default;

    World(shared_ptr<ConcreteFactory> factory, int level);

    void update(Direction d);

private:
    void createEntities(shared_ptr<ConcreteFactory> factory, int level);

    void addEntity(shared_ptr<EntityModel> entity);

    void removeEntity(shared_ptr<EntityModel> entity);

    vector<shared_ptr<EntityModel>> getEntities();

    bool movePacMan(Direction d, double distance);

    bool areRectanglesIntersecting(const Rectangle& rectA, const Rectangle& rectB);

    vector<shared_ptr<EntityModel>> entities;
    shared_ptr<PacManModel> pacman;
    Direction currentDirection = Left;
    double worldTime = 0;
};


#endif //PROJECTAP_WORLD_H
