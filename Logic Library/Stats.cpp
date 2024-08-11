//
// Created by thomas on 11/08/24.
//

#include "Stats.h"

shared_ptr<Stats> Stats::getInstance() {
    static shared_ptr<Stats> instance(new Stats);
    return instance;
}

void Stats::increaseLevel() {
    level++;
}

void Stats::resetLevel() {
    level = 1;
}

int Stats::getLevel() const {
    return level;
}

void Stats::increaseScore(int s) {
    score->increaseScore(s);
}

int Stats::getScore() const {
    return score->getScore();
}

void Stats::increaseDifficulty() {
    difficulty++;
}

int Stats::getDifficulty() const {
    return difficulty;
}

void Stats::decreaseLives() {
    lives--;
}

int Stats::getLives() const {
    return lives;
}
