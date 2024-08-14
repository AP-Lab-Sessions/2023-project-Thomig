//
// Created by thomas on 1/08/24.
//

#include "GhostModel.h"

GhostModel::GhostModel(double x, double y) {
    position = make_pair(x, y);
    startingPosition = make_pair(x, y);
    type = Ghost;
}

void GhostModel::update() {
    if (fearTimer > 0) {
        fearTimer--;
    }
    notify();
}

void GhostModel::setPosition(double x, double y) { position = make_pair(x, y); }

Direction GhostModel::getDirection() {
    return direction;
}

void GhostModel::setDirection(Direction d) {
    direction = d;
}

Rectangle GhostModel::getHitBox() {
    Rectangle hitBox;
    hitBox.x = position.first-0.04+1;
    hitBox.y = position.second-0.04+1;
    hitBox.width = 0.08;
    hitBox.height = 0.08;
    return hitBox;
}

Rectangle GhostModel::getHitBox1() {
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

ghostState GhostModel::getState() {
    if (state == Setup) {  // Ghost out of setup state when leaving starting position
        if (abs((position.first+1)-(startingPosition.first+1)) > 0.2) {
            state = Chase;
        }
    }
    else if (state == Fear) {
        if (fearTimer == 0) {
            state = Chase;
        }
    }
    return state;
}

int GhostModel::getSpriteTimer() { return spriteTimer; }

bool GhostModel::changeDirection() {
    if (changeDirectionTimer > 1500) {
        return true;
    }
    return false;
}

void GhostModel::enableFear() {
    state = Fear;
    fearTimer = 20000;
    shared_ptr<Stats> stats = Stats::getInstance();
    for (int i = 0; i < stats->getDifficulty(); i++) {
        fearTimer *= 0.8;
    }
}

void GhostModel::resetPosition() {
    position = startingPosition;
    direction = Up;
    state = Setup;
    changeDirectionTimer = 0;
    fearTimer = 0;
}

double GhostModel::getSpeed() {
    double speed = 1;
    shared_ptr<Stats> stats = Stats::getInstance();
    for (int i = 0; i < stats->getDifficulty(); i++) {
        speed *= 1.05;
    }
    return speed;
}
