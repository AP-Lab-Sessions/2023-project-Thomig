//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_PAUSEDSTATE_H
#define PROJECTAP_PAUSEDSTATE_H

#include "../State.h"
#include "../StateManager.h"

class PausedState : public State {
public:
    PausedState(std::shared_ptr<StateManager> stateManager);

    void handleEvent(sf::Event& event) override;

    void update() override;

    void render() override;
};


#endif //PROJECTAP_PAUSEDSTATE_H
