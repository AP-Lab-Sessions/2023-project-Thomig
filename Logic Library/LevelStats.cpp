//
// Created by thomas on 21/12/23.
//

#include "LevelStats.h"

shared_ptr<LevelStats> LevelStats::getInstance() {
    static shared_ptr<LevelStats> instance(new LevelStats);
    return instance;
}

LevelStats::LevelStats() {
    lives = 3;
    score = make_shared<Score>();
    difficulty = 0;
}

int LevelStats::getLives() const {
    return lives;
}

int LevelStats::getScore() const {
    return score->getCurrentScore();
}

int LevelStats::getDifficulty() const {
    return difficulty;
}

void LevelStats::addScore(int x) {
    score->add(x);
}

void LevelStats::decScore() {
    score->dec();
}

void LevelStats::decLives() {
    lives--;
}

bool LevelStats::dead() const {
    if (lives == 0) {
        return true;
    }
    return false;
}

void LevelStats::reset() {
    lives = 3;
    score = make_shared<Score>();
    difficulty = 0;
}

void LevelStats::increaseDifficulty() {
    difficulty++;
}

vector<int> LevelStats::getScoreboard() {
    return score->getScoreBoard();
}

void LevelStats::addToScoreboard() {
    score->addToScoreBoard();
}
