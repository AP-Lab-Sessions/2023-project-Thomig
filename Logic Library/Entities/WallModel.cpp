//
// Created by thomas on 1/08/24.
//

#include "WallModel.h"

WallModel::WallModel(double x, double y) {
    position = make_pair(x, y);
    type = Wall;
}

void WallModel::update() {
    notify();
}

Rectangle WallModel::getHitBox() {
    Rectangle hitBox;
    hitBox.x = position.first-0.07+1;
    hitBox.y = position.second-0.07+1;
    hitBox.width = 0.14;
    hitBox.height = 0.14;
    return hitBox;
}
