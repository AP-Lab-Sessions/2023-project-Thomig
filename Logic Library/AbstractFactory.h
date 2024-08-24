//
// Created by thomas on 2/08/24.
//

#ifndef PROJECTAP_ABSTRACTFACTORY_H
#define PROJECTAP_ABSTRACTFACTORY_H

#include "memory"
#include "EntityModel.h"

using namespace std;

class AbstractFactory {
public:
    virtual shared_ptr<EntityModel> createPacMan(double x, double y) = 0;

    virtual shared_ptr<EntityModel> createGhost(double x, double y) = 0;

    virtual shared_ptr<EntityModel> createWall(double x, double y) = 0;

    virtual shared_ptr<EntityModel> createCoin(double x, double y) = 0;

    virtual shared_ptr<EntityModel> createFruit(double x, double y) = 0;

    virtual shared_ptr<EntityModel> createBanana(double x, double y) = 0;

    virtual ~AbstractFactory() = default;
};


#endif //PROJECTAP_ABSTRACTFACTORY_H
