//
// Created by thomas on 4/12/23.
//

#ifndef PROJECTAP_VICTORYSTATE_H
#define PROJECTAP_VICTORYSTATE_H

#include "../State.h"

class VictoryState: public State {
public:
    string getType() override;

    VictoryState();

private:

};


#endif //PROJECTAP_VICTORYSTATE_H
