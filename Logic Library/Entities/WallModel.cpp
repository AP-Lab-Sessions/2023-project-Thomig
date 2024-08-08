//
// Created by thomas on 1/08/24.
//

#include "WallModel.h"

WallModel::WallModel(double x, double y) {
    position = make_pair(x, y);
    type = Wall;
}

void WallModel::update() {
    notify();
}
