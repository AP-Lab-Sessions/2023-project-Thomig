
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
#include "Random.h"
#include "Stats.h"

using namespace std;

class World {
public:
    World() = default;

    World(shared_ptr<ConcreteFactory> factory);

    void update(Direction d);

private:
    // Entity Controller
    void createEntities();

    void addEntity(shared_ptr<EntityModel> entity);

    void removeEntity(shared_ptr<EntityModel> entity);

    bool movePacMan(Direction d, double distance);

    void moveGhosts(shared_ptr<GhostModel> ghost, double distance);

    void moveGhost(shared_ptr<GhostModel> ghost, Direction d, double distance);

    bool areRectanglesIntersecting(const Rectangle& rectA, const Rectangle& rectB);

    double calculateManhattanDistance(shared_ptr<GhostModel> ghost, Direction d, double distance);

    bool levelCompleted();

    shared_ptr<ConcreteFactory> factory;
    vector<shared_ptr<EntityModel>> entities;
    shared_ptr<PacManModel> pacman;
    vector<shared_ptr<GhostModel>> ghosts;
    Direction currentDirection = Left;
    double spriteUpdateTime = 0;
    double worldTime = 0;
    vector<pair<double, double>> bananaPositions;
    int bananaTimer = 0;
    double coinPickupInterval = 0;
};


#endif //PROJECTAP_WORLD_H
