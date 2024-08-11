
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

// Entity Controller
class World {
public:
    World() = default;

    World(shared_ptr<ConcreteFactory> factory);

    void update(Direction d);

private:
    void createEntities(shared_ptr<ConcreteFactory> factory, int level);

    void addEntity(shared_ptr<EntityModel> entity);

    void removeEntity(shared_ptr<EntityModel> entity);

    vector<shared_ptr<EntityModel>> getEntities();

    bool movePacMan(Direction d, double distance);

    void moveGhosts(shared_ptr<GhostModel> ghost, double distance);

    void moveGhost(shared_ptr<GhostModel> ghost, Direction d, double distance);

    bool areRectanglesIntersecting(const Rectangle& rectA, const Rectangle& rectB);

    double calculateManhattanDistance(shared_ptr<GhostModel> ghost, Direction d, double distance);

    vector<shared_ptr<EntityModel>> entities;
    shared_ptr<PacManModel> pacman;
    vector<shared_ptr<GhostModel>> ghosts;
    Direction currentDirection = Left;
    double worldTime = 0;
    double spriteUpdateTime = 0;
};


#endif //PROJECTAP_WORLD_H
