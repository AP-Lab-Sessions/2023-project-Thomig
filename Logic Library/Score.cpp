//
// Created by thomas on 8/08/24.
//

#include "Score.h"

Score::Score() {}

void Score::update() {}

void Score::increaseScore(int s) {
    this->score += s;
}

int Score::getScore() {
    return score;
}
