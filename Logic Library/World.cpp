//
// Created by thomas on 1/08/24.
//

#include "World.h"

World::World(shared_ptr<ConcreteFactory> factory, int level) {
    createEntities(factory, level);
}
