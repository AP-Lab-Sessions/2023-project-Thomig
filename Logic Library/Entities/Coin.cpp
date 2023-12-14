//
// Created by thomas on 11/12/23.
//

#include "Coin.h"

string Coin::getType() {
    return "Coin";
}

Coin::Coin(const pair<float, float> &position) : Entity(position) {}

vector<float> Coin::getHitbox() {
    float x = 0.01; // size of hitbox in every direction of position
    return {getPosition().first-x, getPosition().second+x, getPosition().first+x, getPosition().second-x};
}
