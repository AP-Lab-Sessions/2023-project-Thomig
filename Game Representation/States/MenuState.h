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
    MenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
        cout << "Creating menu state" << endl;
    }

    void handleEvent(sf::Event& event) override {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
            stateManager->pushState(std::make_shared<LevelState>(stateManager));
        }
    }

    void update(float deltaTime) override {
        // Update menu items
    }

    void render(sf::RenderWindow& window) override {
        cout << "Rendering menu state" << endl;
        // Render menu items
    }
};

#endif //PROJECTAP_MENUSTATE_H
