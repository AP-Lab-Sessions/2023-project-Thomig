//
// Created by thomas on 8/08/24.
//

#ifndef PROJECTAP_SCORE_H
#define PROJECTAP_SCORE_H

#include "Observer.h"
#include "vector"
#include "algorithm"
#include "fstream"
#include "sstream"
#include "iostream"

using namespace std;

class Score : public Observer {
public:
    Score();

    void update() override;

    void increaseScore(int s);

    void decreaseScore();

    int getScore();

    void resetScore();

    void addToScoreBoard();

    vector<int> getScoreBoard();

    ~Score() override = default;

private:
    int score = 0;
};


#endif //PROJECTAP_SCORE_H
