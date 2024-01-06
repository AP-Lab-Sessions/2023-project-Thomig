#ifndef PROJECTAP_STATEMANAGER_H
#define PROJECTAP_STATEMANAGER_H

#include "States/LevelState.h"
#include "States/MenuState.h"
#include "States/PausedState.h"
#include "States/VictoryState.h"
#include "States/GameOverState.h"
#include "memory"
#include "stack"
#include <SFML/Graphics.hpp>

using namespace std;

class StateManager {
private:
    stack<shared_ptr<State>> stateStack;

public:
    // constructor
    StateManager();

    string getCurrentStateType();

    shared_ptr<State> getCurrentState();

    // change state according to current state and key pressed
    void changeState(sf::Keyboard::Key key);

    void toGameOver();

    void toVictoryState();

};


#endif //PROJECTAP_STATEMANAGER_H
