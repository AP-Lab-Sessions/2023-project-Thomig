//
// Created by thomas on 11/12/23.
//

#include "Wall.h"

string Wall::getType() {
    return "Wall";
}

Wall::Wall(const pair<float, float> &position) : Entity(position) {}

vector<float> Wall::getHitbox() {
    float x = 0.02;  // size of hitbox in every direction of position
    return {getPosition().first-x, getPosition().second+x, getPosition().first+x, getPosition().second-x};
}
