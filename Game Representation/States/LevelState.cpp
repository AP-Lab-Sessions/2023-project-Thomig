//
// Created by thomas on 30/07/24.
//

#include "LevelState.h"

LevelState::LevelState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
    // Initialize level (e.g., create World instance)
}

void LevelState::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        stateManager->pushState(std::make_shared<PausedState>(stateManager));
    }
}

void LevelState::update(float deltaTime) {
    // Update game logic
}

void LevelState::render(sf::RenderWindow &window) {
    cout << "Rendering level state" << endl;
    // Render game world
}
