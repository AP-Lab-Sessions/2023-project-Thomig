//
// Created by thomas on 14/08/24.
//

#include "BananaModel.h"

BananaModel::BananaModel(double x, double y) {
    position = make_pair(x, y);
    type = Banana;
}

void BananaModel::update() {
    notify();
}

Rectangle BananaModel::getHitBox() {
    Rectangle hitBox;
    hitBox.x = position.first-0.03+1;
    hitBox.y = position.second-0.03+1;
    hitBox.width = 0.06;
    hitBox.height = 0.06;
    return hitBox;
}
