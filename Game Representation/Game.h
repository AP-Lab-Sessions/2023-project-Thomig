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

class Game {
public:
    Game();

    void start();

private:
    void handleEvents();

    void update(float deltaTime);

    void render();

    sf::RenderWindow window;
    shared_ptr<StateManager> stateManager;
    shared_ptr<AbstractFactory> factory = make_shared<ConcreteFactory>();
};



#endif //PROJECTAP_GAME_H
