//
// Created by thomas on 11/08/24.
//

#ifndef PROJECTAP_STATS_H
#define PROJECTAP_STATS_H

#include "memory"
#include "Score.h"

using namespace std;

class Stats {
public:
    static shared_ptr<Stats> getInstance();

    void increaseLevel();
    void resetLevel();
    int getLevel() const;
    void increaseScore(int s);
    int getScore() const;
    void increaseDifficulty();
    int getDifficulty() const;
    void decreaseLives();
    int getLives() const;

private:
    Stats() {};

    int level = 1;
    shared_ptr<Score> score = make_shared<Score>();
    int difficulty = 0;    // per difficulty increase: fear duration -20% and ghost speed +5%
    int lives = 3;
};

#endif //PROJECTAP_STATS_H