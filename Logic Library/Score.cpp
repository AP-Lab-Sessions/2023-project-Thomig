//
// Created by thomas on 8/08/24.
//

#include "Score.h"

Score::Score() {}

void Score::update() {}

void Score::increaseScore(int s) {
    this->score += s;
}

void Score::decreaseScore() {
    if (score > 0) {
        score--;
    }
}

int Score::getScore() {
    return score;
}

void Score::resetScore() {
    score = 0;
}
