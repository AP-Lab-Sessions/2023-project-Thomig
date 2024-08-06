//
// Created by thomas on 30/07/24.
//

#include "LevelState.h"

LevelState::LevelState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
    world = World(stateManager->getFactory(), 1);
}

void LevelState::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        stateManager->pushState(std::make_shared<PausedState>(stateManager));
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left or
             event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
        direction = Left;
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right or
             event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
        direction = Right;
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up or
             event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) {
        direction = Up;
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down or
             event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
        direction = Down;
    }
}

void LevelState::update() {
    world.update(direction);
}

void LevelState::render() {
    // Render game
    world.render();
}
