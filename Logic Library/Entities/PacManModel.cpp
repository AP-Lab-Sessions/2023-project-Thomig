//
// Created by thomas on 1/08/24.
//

#include "PacManModel.h"

PacManModel::PacManModel(double x, double y) {
    position = make_pair(x, y);
    type = PacMan;
}

void PacManModel::update() {
    notify();
}

Direction PacManModel::getDirection() {return direction; }

void PacManModel::setDirection(Direction d) { direction = d; }

Rectangle PacManModel::getHitBox() {
    Rectangle hitBox;
    hitBox.x = position.first-0.01+1;
    hitBox.y = position.second-0.01+1;
    hitBox.width = 0.02;
    hitBox.height = 0.02;
    return hitBox;
}
