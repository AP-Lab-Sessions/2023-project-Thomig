//
// Created by thomas on 21/12/23.
//

#ifndef PROJECTAP_LEVELSTATS_H
#define PROJECTAP_LEVELSTATS_H

#include "memory"
#include "Score.h"
#include "StopWatch.h"

using namespace std;

// singleton class to keep stats about a current playthrough
class LevelStats {
public:
    static shared_ptr<LevelStats> getInstance();

    int getLives() const;

    int getScore() const;

    int getDifficulty() const;

    void addScore(int x);

    void decScore();

    void decLives();

    [[nodiscard]] bool dead() const;

    void reset();

    void increaseDifficulty();

    vector<int> getScoreboard();

    void addToScoreboard();

private:
    LevelStats();

    int lives;
    shared_ptr<Score> score;
    int difficulty;    // per difficulty increase: fear duration -20% and ghost speed +5%
};


#endif //PROJECTAP_LEVELSTATS_H
