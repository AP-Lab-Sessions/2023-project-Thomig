//
// Created by thomas on 30/07/24.
//

#include "LevelState.h"

LevelState::LevelState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
    World world(stateManager->getFactory());
}

void LevelState::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        stateManager->pushState(std::make_shared<PausedState>(stateManager));
    }
}

void LevelState::update(float deltaTime) {
    // Update game logic
}

void LevelState::render() {
    // Render game world
}
