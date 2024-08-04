
//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_WORLD_H
#define PROJECTAP_WORLD_H

#include <vector>
#include "algorithm"
#include "memory"
#include "EntityModel.h"
#include "AbstractFactory.h"

using namespace std;

class World {
public:
    World(shared_ptr<AbstractFactory> factory) {
        createEntities(factory);
    }

    void createEntities(shared_ptr<AbstractFactory> factory) {
        addEntity(factory->createPacMan(0, 0));
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

    void update() {
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
};


#endif //PROJECTAP_WORLD_H
