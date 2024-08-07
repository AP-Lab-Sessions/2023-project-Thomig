
//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_WORLD_H
#define PROJECTAP_WORLD_H

#include <vector>
#include "algorithm"
#include "memory"
#include "EntityModel.h"
#include "../Game Representation/ConcreteFactory.h"

using namespace std;

enum Direction {
    Up,
    Down,
    Left,
    Right
};

// Entity Controller
class World {
public:
    World() = default;

    World(shared_ptr<ConcreteFactory> factory, int level);

    void createEntities(shared_ptr<ConcreteFactory> factory, int level) {
        addEntity(factory->createPacMan(-1, -0.9));
        addEntity(factory->createWall(-1, -1));
        addEntity(factory->createWall(-0.9, -0.9));
        addEntity(factory->createWall(0.9, 0.1));
    }

    void addEntity(shared_ptr<EntityModel> entity) {
        entities.push_back(entity);
    }

    void removeEntity(shared_ptr<EntityModel> entity) {
        entities.erase(remove(entities.begin(), entities.end(), entity), entities.end());
    }

    vector<shared_ptr<EntityModel>> getEntities() {
        return entities;
    }

    void update(Direction d) {
        for (auto entity : entities) {
            entity->update();
        }
    }

    void render() {
        //for (auto entity : entities) {
        //    entity->render();
        //}
    }
private:
    vector<shared_ptr<EntityModel>> entities;
    Direction direction = Left;
};


#endif //PROJECTAP_WORLD_H
