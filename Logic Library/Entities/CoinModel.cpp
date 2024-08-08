//
// Created by thomas on 1/08/24.
//

#include "CoinModel.h"

CoinModel::CoinModel(double x, double y) {
    position = make_pair(x, y);
    type = Coin;
}

void CoinModel::update() {
    notify();
}
