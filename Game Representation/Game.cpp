//
// Created by thomas on 30/07/24.
//

#include "Game.h"

Game::Game() : window(sf::VideoMode(1920, 1080), "Pacman"), stateManager(make_shared<StateManager>()) {
    stateManager->pushState(make_shared<MenuState>(stateManager));
}

void Game::start() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        stateManager->handleEvent(event);
    }
}

void Game::update(float deltaTime) {
    stateManager->update(deltaTime);
}

void Game::render() {
    window.clear();
    stateManager->render(window);
    window.display();
}
