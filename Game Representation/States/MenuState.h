//
// Created by thomas on 4/12/23.
//

#ifndef PROJECTAP_MENUSTATE_H
#define PROJECTAP_MENUSTATE_H

#include "../State.h"

class MenuState : public State {
public:
    string getType() override;

    MenuState();

    void update() override;
};


#endif //PROJECTAP_MENUSTATE_H
