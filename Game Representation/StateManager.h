//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_STATEMANAGER_H
#define PROJECTAP_STATEMANAGER_H

#include <stack>
#include <memory>
#include <SFML/Graphics.hpp>
#include "State.h"

class StateManager {
public:
    void pushState(std::shared_ptr<State> state) {
        states.push(state);
    }

    void popState() {
        if (!states.empty()) {
            states.pop();
        }
    }

    void handleEvent(sf::Event& event) {
        if (!states.empty()) {
            states.top()->handleEvent(event);
        }
    }

    void update(float deltaTime) {
        if (!states.empty()) {
            states.top()->update(deltaTime);
        }
    }

    void render(sf::RenderWindow& window) {
        if (!states.empty()) {
            states.top()->render(window);
        }
    }

private:
    std::stack<std::shared_ptr<State>> states;
};

#endif //PROJECTAP_STATEMANAGER_H
