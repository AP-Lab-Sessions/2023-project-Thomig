//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_GAME_H
#define PROJECTAP_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "StateManager.h"
#include "States/MenuState.h"

class Game {
public:
    Game() : window(sf::VideoMode(800, 600), "Pacman"), stateManager(std::make_shared<StateManager>()) {
        stateManager->pushState(std::make_shared<MenuState>(stateManager));
    }

    void start() {
        while (window.isOpen()) {
            handleEvents();
            render();
        }
    }

private:
    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            stateManager->handleEvent(event);
        }
    }

    void update(float deltaTime) {
        stateManager->update(deltaTime);
    }

    void render() {
        window.clear();
        stateManager->render(window);
        window.display();
    }

    sf::RenderWindow window;
    std::shared_ptr<StateManager> stateManager;
};



#endif //PROJECTAP_GAME_H
