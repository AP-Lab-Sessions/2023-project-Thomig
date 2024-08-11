//
// Created by thomas on 1/08/24.
//

#include "GhostModel.h"

GhostModel::GhostModel(double x, double y) {
    position = make_pair(x, y);
    type = Ghost;
}

void GhostModel::update() {
    notify();
}

Direction GhostModel::getDirection() {
    return direction;
}

void GhostModel::setDirection(Direction d) {
    direction = d;
}

Rectangle GhostModel::getHitBox() {
    Rectangle hitBox;
    hitBox.x = position.first-0.01+1;
    hitBox.y = position.second-0.01+1;
    hitBox.width = 0.02;
    hitBox.height = 0.02;
    return hitBox;
}

void GhostModel::incrementSpriteTimer() {
    if (spriteTimer == 1) {
        spriteTimer = 0;
    } else {
        spriteTimer++;
    }
}

bool GhostModel::changeDirection() {
    if (changeDirectionTimer > 500) {
        return true;
    }
    return false;
}
