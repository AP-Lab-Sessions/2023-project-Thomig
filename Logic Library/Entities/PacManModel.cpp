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
