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
    LevelState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
        // Initialize level (e.g., create World instance)
    }

    void handleEvent(sf::Event& event) override {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            stateManager->pushState(std::make_shared<PausedState>(stateManager));
        }
    }

    void update(float deltaTime) override {
        // Update game logic
    }

    void render(sf::RenderWindow& window) override {
        cout << "Rendering level state" << endl;
        // Render game world
    }
};



#endif //PROJECTAP_LEVELSTATE_H
