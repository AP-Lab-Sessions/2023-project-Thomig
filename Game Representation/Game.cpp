//
// Created by thomas on 30/07/24.
//

#include "Game.h"

Game::Game() {
    // Initialize basic game components
    int width = 1850; // 1850
    int height = 1016; // 1016
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

        // Check for mouse click events
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                Camera &camera = Camera::getInstance();
                // Get the mouse position relative to the window
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

                // Check if the mouse click occurred within the bounds of the buttons
                int playButtonX = camera.modelWidth(780);
                int playButtonY = camera.modelHeight(725);
                int continueButtonX = camera.modelWidth(780);
                int continueButtonY = camera.modelHeight(375);
                int homeButtonX = camera.modelWidth(780);
                int homeButtonY = camera.modelHeight(525);
                int buttonWidth = camera.modelWidth(300);
                int buttonHeight = camera.modelHeight(100);
                if (mousePos.x >= playButtonX && mousePos.x <= (playButtonX + buttonWidth) &&
                    mousePos.y >= playButtonY && mousePos.y <= (playButtonY + buttonHeight)) {
                    stateManager->handleMouseClick("Play");
                } else if (mousePos.x >= continueButtonX && mousePos.x <= (continueButtonX + buttonWidth) &&
                           mousePos.y >= continueButtonY && mousePos.y <= (continueButtonY + buttonHeight)) {
                    stateManager->handleMouseClick("Continue");
                } else if (mousePos.x >= homeButtonX && mousePos.x <= (homeButtonX + buttonWidth) &&
                           mousePos.y >= homeButtonY && mousePos.y <= (homeButtonY + buttonHeight)) {
                    stateManager->handleMouseClick("Home");
                }
            }
        }
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
