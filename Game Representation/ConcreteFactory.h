//
// Created by thomas on 2/08/24.
//

#ifndef PROJECTAP_CONCRETEFACTORY_H
#define PROJECTAP_CONCRETEFACTORY_H

#include "../Logic Library/AbstractFactory.h"
#include "../Logic Library/Entities/PacManModel.h"
#include "Entities/PacManView.h"
#include "../Logic Library/Entities/GhostModel.h"
#include "Entities/GhostView.h"
#include "../Logic Library/Entities/WallModel.h"
#include "Entities/WallView.h"
#include "../Logic Library/Entities/CoinModel.h"
#include "Entities/CoinView.h"
#include "../Logic Library/Entities/FruitModel.h"
#include "Entities/FruitView.h"
#include "../Logic Library/Entities/BananaModel.h"
#include "Entities/BananaView.h"

class ConcreteFactory : public AbstractFactory {
public:
    shared_ptr<EntityModel> createPacMan(double x, double y) override;

    shared_ptr<EntityModel> createGhost(double x, double y) override;

    shared_ptr<EntityModel> createWall(double x, double y) override;

    shared_ptr<EntityModel> createCoin(double x, double y) override;

    shared_ptr<EntityModel> createFruit(double x, double y) override;

    shared_ptr<EntityModel> createBanana(double x, double y) override;
};


#endif //PROJECTAP_CONCRETEFACTORY_H
