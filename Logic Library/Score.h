#ifndef ADVANCED_PROGRAMMING_GAME_SCORE_H
#define ADVANCED_PROGRAMMING_GAME_SCORE_H

#include <fstream>
#include <vector>
#include <sstream>
#include "iostream"
#include "algorithm"

using namespace std;

// Calculates score
// Stores top 5 scores in file: ScoreBoard.txt
class Score {
public:
    // adds given number to current score
    void add(int x);

    // returns the current score
    int getCurrentScore() const;

    // adds new value to scoreboard if necessary
    void addToScoreBoard();

    // gets all 5 scores from scoreboard
    static vector<int> getScoreBoard();

    Score();

private:
    int currentScore = 0;
};

#endif // ADVANCED_PROGRAMMING_GAME_SCORE_H
