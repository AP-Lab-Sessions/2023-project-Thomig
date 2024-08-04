//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_STATEMANAGER_H
#define PROJECTAP_STATEMANAGER_H

#include <stack>
#include <memory>
#include <SFML/Graphics.hpp>
#include "State.h"

class StateManager {
public:
    void pushState(std::shared_ptr<State> state);

    void popState();

    void handleEvent(sf::Event& event);

    void update(float deltaTime);

    void render(sf::RenderWindow& window);

private:
    std::stack<std::shared_ptr<State>> states;
};

#endif //PROJECTAP_STATEMANAGER_H
