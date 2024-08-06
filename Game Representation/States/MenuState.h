//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_MENUSTATE_H
#define PROJECTAP_MENUSTATE_H

#include "../State.h"
#include "../StateManager.h"
#include "LevelState.h"

class MenuState : public State {
public:
    MenuState(std::shared_ptr<StateManager> stateManager);

    void handleEvent(sf::Event& event) override;

    void update(float deltaTime) override;

    void render() override;
};

#endif //PROJECTAP_MENUSTATE_H
