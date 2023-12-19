//
// Created by thomas on 4/12/23.
//

#ifndef PROJECTAP_PAUSEDSTATE_H
#define PROJECTAP_PAUSEDSTATE_H

#include "../State.h"

class PausedState: public State {
public:
    string getType() override;

    PausedState();

};


#endif //PROJECTAP_PAUSEDSTATE_H
