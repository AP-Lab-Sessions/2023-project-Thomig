//
// Created by thomas on 31/07/24.
//

#ifndef PROJECTAP_STATE_H
#define PROJECTAP_STATE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "iostream"

using namespace std;

class StateManager;

class State {
public:
    State(std::shared_ptr<StateManager> manager);
    virtual ~State() = default;
    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

protected:
    shared_ptr<StateManager> stateManager;
};



#endif //PROJECTAP_STATE_H
