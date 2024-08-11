//
// Created by thomas on 8/08/24.
//

#ifndef PROJECTAP_SCORE_H
#define PROJECTAP_SCORE_H

#include "Observer.h"

class Score: public Observer {
public:
    Score();
    void update() override;
    void increaseScore(int s);
    int getScore();
    ~Score() override = default;
private:
    int score = 0;
};


#endif //PROJECTAP_SCORE_H
