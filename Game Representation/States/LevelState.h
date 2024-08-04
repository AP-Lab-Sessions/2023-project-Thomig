//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_LEVELSTATE_H
#define PROJECTAP_LEVELSTATE_H

#include "../State.h"
#include "../StateManager.h"
#include "PausedState.h"

class LevelState : public State {
public:
    LevelState(std::shared_ptr<StateManager> stateManager);

    void handleEvent(sf::Event& event) override;

    void update(float deltaTime) override;

    void render(sf::RenderWindow& window) override;
};



#endif //PROJECTAP_LEVELSTATE_H
