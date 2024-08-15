//
// Created by thomas on 11/08/24.
//

#include "Stats.h"

shared_ptr<Stats> Stats::getInstance() {
    static shared_ptr<Stats> instance(new Stats);
    return instance;
}

void Stats::increaseLevel() {
    if (level < 3) {
        level++;
    }
    else {
        level = 1;
    }
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

void Stats::changeLevelCompleted() {
    levelCompleted = !levelCompleted;
}

bool Stats::isLevelCompleted() const {
    return levelCompleted;
}

void Stats::resetStats() {
    level = 1;
    score->resetScore();
    difficulty = 0;
    lives = 3;
    levelCompleted = false;
}

bool Stats::getResetWorldClock() const {
    return resetWorldClock;
}

void Stats::switchResetWorldClock() {
    resetWorldClock = !resetWorldClock;
}

void Stats::decreaseScore() {
    score->decreaseScore();
}

vector<int> Stats::getScoreBoard() {
    return score->getScoreBoard();
}

void Stats::addToScoreBoard() {
    score->addToScoreBoard();
}
