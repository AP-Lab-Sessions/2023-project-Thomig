//
// Created by thomas on 30/07/24.
//

#include "StateManager.h"

void StateManager::pushState(std::shared_ptr<State> state) {
    states.push(state);
}

void StateManager::popState() {
    if (!states.empty()) {
        states.pop();
    }
}

void StateManager::handleEvent(sf::Event &event) {
    if (!states.empty()) {
        states.top()->handleEvent(event);
    }
}

void StateManager::update(float deltaTime) {
    if (!states.empty()) {
        states.top()->update(deltaTime);
    }
}

void StateManager::render(sf::RenderWindow &window) {
    if (!states.empty()) {
        states.top()->render(window);
    }
}
