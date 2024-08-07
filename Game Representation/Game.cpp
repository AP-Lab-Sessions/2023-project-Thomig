//
// Created by thomas on 30/07/24.
//

#include "Game.h"

Game::Game(){
    // Initialize basic game components
    int width = 1850;
    int height = 1016;
    RenderWindow::getInstance().initialize(width, height, "Pacman Game");
    window = RenderWindow::getInstance().getWindow();
    Camera::getInstance();
    factory = std::make_shared<ConcreteFactory>();
    stateManager = std::make_shared<StateManager>(factory);
    stateManager->pushState(std::make_shared<MenuState>(stateManager));
}

void Game::start() {
    while (window->isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        stateManager->handleEvent(event);
    }
}

void Game::update() {
    window->clear();
    stateManager->update();
}

void Game::render() {
    stateManager->render();
    window->display();
}
