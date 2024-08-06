//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_STATEMANAGER_H
#define PROJECTAP_STATEMANAGER_H

#include <stack>
#include <memory>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "ConcreteFactory.h"

using namespace std;

class StateManager {
public:
    StateManager(shared_ptr<ConcreteFactory> factory);

    void pushState(std::shared_ptr<State> state);

    void popState();

    void handleEvent(sf::Event& event);

    void update(float deltaTime);

    void render();

    shared_ptr<ConcreteFactory> getFactory();

private:
    stack<std::shared_ptr<State>> states;
    shared_ptr<ConcreteFactory> factory = make_shared<ConcreteFactory>();
};

#endif //PROJECTAP_STATEMANAGER_H
