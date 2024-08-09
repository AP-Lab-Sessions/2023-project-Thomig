//
// Created by thomas on 1/08/24.
//

#include "FruitModel.h"

FruitModel::FruitModel(double x, double y) {
    position = make_pair(x, y);
    type = Fruit;
}

void FruitModel::update() {
    notify();
}

Rectangle FruitModel::getHitBox() {
    Rectangle hitBox;
    hitBox.x = position.first-0.01+1;
    hitBox.y = position.second-0.01+1;
    hitBox.width = 0.02;
    hitBox.height = 0.02;
    return hitBox;
}
