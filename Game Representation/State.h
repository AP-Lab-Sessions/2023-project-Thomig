//
// Created by thomas on 31/07/24.
//

#ifndef PROJECTAP_STATE_H
#define PROJECTAP_STATE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "iostream"
#include "../Logic Library/World.h"
#include "../Logic Library/Stats.h"
#include "RenderWindow.h"

using namespace std;

class StateManager;

class State {
public:
    State(std::shared_ptr<StateManager> manager);

    virtual ~State() = default;

    virtual void handleEvent(sf::Event &event) = 0;

    virtual void handleMouseClick(string button) = 0;

    virtual void update() = 0;

    virtual void render() = 0;

protected:
    shared_ptr<StateManager> stateManager;
    shared_ptr<sf::RenderWindow> window = RenderWindow::getInstance().getWindow();
    shared_ptr<sf::Font> font;
};


#endif //PROJECTAP_STATE_H
