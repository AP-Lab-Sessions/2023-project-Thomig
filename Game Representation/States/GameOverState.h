//
// Created by thomas on 5/12/23.
//

#ifndef PROJECTAP_GAMEOVERSTATE_H
#define PROJECTAP_GAMEOVERSTATE_H

#include "../State.h"

class GameOverState : public State {
public:
    string getType() override;

    GameOverState();

};


#endif //PROJECTAP_GAMEOVERSTATE_H
