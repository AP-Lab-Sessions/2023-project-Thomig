//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_PAUSEDSTATE_H
#define PROJECTAP_PAUSEDSTATE_H

#include "../State.h"
#include "../StateManager.h"

class PausedState : public State {
public:
    PausedState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {}

    void handleEvent(sf::Event& event) override {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            stateManager->pushState(std::make_shared<PausedState>(stateManager));
        }
    }

    void update(float deltaTime) override {
        // Update game logic
    }

    void render(sf::RenderWindow& window) override {
        cout << "Rendering paused state" << endl;
        // Render game world
    }
};


#endif //PROJECTAP_PAUSEDSTATE_H
