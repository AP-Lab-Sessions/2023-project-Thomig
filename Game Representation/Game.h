//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_GAME_H
#define PROJECTAP_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "StateManager.h"
#include "States/MenuState.h"
#include "ConcreteFactory.h"
#include "RenderWindow.h"
#include "Camera.h"

class Game {
public:
    Game();

    void start();

private:
    void handleEvents();

    void update();

    void render();

    shared_ptr<StateManager> stateManager;
    shared_ptr<ConcreteFactory> factory;
    shared_ptr<sf::RenderWindow> window;
};



#endif //PROJECTAP_GAME_H
