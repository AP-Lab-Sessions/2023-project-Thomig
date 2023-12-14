//
// Created by thomas on 11/12/23.
//

#include "Ghost.h"

string Ghost::getType() {
    return "Ghost";
}

Ghost::Ghost(const pair<float, float> &position, const string &color) : Entity(position), color(color) {}
