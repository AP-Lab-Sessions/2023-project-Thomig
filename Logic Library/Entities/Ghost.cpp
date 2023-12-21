//
// Created by thomas on 11/12/23.
//

#include "Ghost.h"

string Ghost::getType() {
    return "Ghost";
}

Ghost::Ghost(const pair<float, float> &position, const string &color) : Entity(position), color(color) {}

const string &Ghost::getColor() const {
    return color;
}

vector<float> Ghost::getHitbox() {
    float x = 0.027;   // size of hitbox in every direction of position
    return {getPosition().first-x, getPosition().second+x, getPosition().first+x, getPosition().second-x};
}
