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

    int getLevel() const;

    void increaseScore(int s);

    int getScore() const;

    void increaseDifficulty();

    int getDifficulty() const;

    void decreaseLives();

    int getLives() const;

    void changeLevelCompleted();

    bool isLevelCompleted() const;

    void resetStats();

    bool getResetWorldClock() const;

    void switchResetWorldClock();

    void decreaseScore();

    vector<int> getScoreBoard();

    void addToScoreBoard();

    void setFps(int f);

    int getFps() const;

private:
    Stats() {};

    int level = 1;
    shared_ptr<Score> score = make_shared<Score>();
    int difficulty = 0;    // per difficulty increase: fear duration -20% and ghost speed +5%
    int lives = 3;
    bool levelCompleted = false;
    bool resetWorldClock = false;
    int fps = 0;
};

#endif //PROJECTAP_STATS_H