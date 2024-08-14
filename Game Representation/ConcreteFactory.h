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

class ConcreteFactory: public AbstractFactory {
public:
    shared_ptr<EntityModel> createPacMan(double x, double y) override {
        auto pacManModel = make_shared<PacManModel>(x, y);
        auto pacManView = make_shared<PacManView>(pacManModel);
        pacManModel->attachView(pacManView);
        return pacManModel;
    }

    shared_ptr<EntityModel> createGhost(double x, double y) override {
        auto ghostModel = make_shared<GhostModel>(x, y);
        auto ghostView = make_shared<GhostView>(ghostModel);
        ghostModel->attachView(ghostView);
        return ghostModel;
    }

    shared_ptr<EntityModel> createWall(double x, double y) override {
        auto wallModel = make_shared<WallModel>(x, y);
        // Assuming WallView exists and follows the same pattern
        auto wallView = make_shared<WallView>(wallModel);
        wallModel->attachView(wallView);
        return wallModel;
    }

    shared_ptr<EntityModel> createCoin(double x, double y) override {
        auto coinModel = make_shared<CoinModel>(x, y);
        auto coinView = make_shared<CoinView>(coinModel);
        coinModel->attachView(coinView);
        return coinModel;
    }

    shared_ptr<EntityModel> createFruit(double x, double y) override {
        auto fruitModel = make_shared<FruitModel>(x, y);
        auto fruitView = make_shared<FruitView>(fruitModel);
        fruitModel->attachView(fruitView);
        return fruitModel;
    }

    shared_ptr<EntityModel> createBanana(double x, double y) override {
        auto bananaModel = make_shared<BananaModel>(x, y);
        auto bananaView = make_shared<BananaView>(bananaModel);
        bananaModel->attachView(bananaView);
        return bananaModel;
    }
};


#endif //PROJECTAP_CONCRETEFACTORY_H
