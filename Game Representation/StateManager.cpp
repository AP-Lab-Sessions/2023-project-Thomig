//
// Created by thomas on 30/07/24.
//

#include "StateManager.h"

StateManager::StateManager(shared_ptr<ConcreteFactory> factory) {
    this->factory = factory;
}

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

void StateManager::handleMouseClick(string button) {
    if (!states.empty()) {
        states.top()->handleMouseClick(button);
    }
}

void StateManager::update() {
    if (!states.empty()) {
        states.top()->update();
    }
}

void StateManager::render() {
    if (!states.empty()) {
        states.top()->render();
    }
}

shared_ptr<ConcreteFactory> StateManager::getFactory() {
    return factory;
}
