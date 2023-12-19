//
// Created by thomas on 4/12/23.
//

#ifndef PROJECTAP_MENUSTATE_H
#define PROJECTAP_MENUSTATE_H

#include "../State.h"

class MenuState: public State {
public:
    string getType() override;

    MenuState();

};


#endif //PROJECTAP_MENUSTATE_H
