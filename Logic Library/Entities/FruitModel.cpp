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
