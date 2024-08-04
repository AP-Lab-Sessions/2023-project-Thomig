//
// Created by thomas on 1/08/24.
//

#include "GhostModel.h"

GhostModel::GhostModel(double x, double y) {
    position = make_pair(x, y);
}

void GhostModel::update() {
    notify();
}
