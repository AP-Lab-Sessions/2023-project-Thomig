//
// Created by thomas on 2/08/24.
//

#include "ConcreteFactory.h"

shared_ptr<EntityModel> ConcreteFactory::createPacMan(double x, double y) {
    auto pacManModel = make_shared<PacManModel>(x, y);
    auto pacManView = make_shared<PacManView>(pacManModel);
    pacManModel->attachView(pacManView);
    return pacManModel;
}

shared_ptr<EntityModel> ConcreteFactory::createGhost(double x, double y) {
    auto ghostModel = make_shared<GhostModel>(x, y);
    auto ghostView = make_shared<GhostView>(ghostModel);
    ghostModel->attachView(ghostView);
    return ghostModel;
}

shared_ptr<EntityModel> ConcreteFactory::createWall(double x, double y) {
    auto wallModel = make_shared<WallModel>(x, y);
    auto wallView = make_shared<WallView>(wallModel);
    wallModel->attachView(wallView);
    return wallModel;
}

shared_ptr<EntityModel> ConcreteFactory::createCoin(double x, double y) {
    auto coinModel = make_shared<CoinModel>(x, y);
    auto coinView = make_shared<CoinView>(coinModel);
    coinModel->attachView(coinView);
    return coinModel;
}

shared_ptr<EntityModel> ConcreteFactory::createFruit(double x, double y) {
    auto fruitModel = make_shared<FruitModel>(x, y);
    auto fruitView = make_shared<FruitView>(fruitModel);
    fruitModel->attachView(fruitView);
    return fruitModel;
}

shared_ptr<EntityModel> ConcreteFactory::createBanana(double x, double y) {
    auto bananaModel = make_shared<BananaModel>(x, y);
    auto bananaView = make_shared<BananaView>(bananaModel);
    bananaModel->attachView(bananaView);
    return bananaModel;
}
