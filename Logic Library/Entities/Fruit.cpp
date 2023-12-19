//
// Created by thomas on 11/12/23.
//

#include "Fruit.h"

string Fruit::getType() {
    return "Fruit";
}

Fruit::Fruit(const pair<float, float> &position) : Entity(position) {}

vector<float> Fruit::getHitbox() {
    float x = 0.01;  // size of hitbox in every direction of position
    return {getPosition().first-x, getPosition().second+x, getPosition().first+x, getPosition().second-x};
}