//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_PAUSEDSTATE_H
#define PROJECTAP_PAUSEDSTATE_H

#include "../State.h"
#include "../StateManager.h"

class PausedState : public State {
public:
    PausedState(std::shared_ptr<StateManager> stateManager);

    void handleEvent(sf::Event &event) override;

    void handleMouseClick(string button) override;

    void update() override;

    void render() override;

private:
    shared_ptr<sf::Shape> background;
    shared_ptr<sf::Text> pausedText;
    shared_ptr<sf::Shape> homeButton;
    shared_ptr<sf::Text> homeText;
    shared_ptr<sf::Shape> continueButton;
    shared_ptr<sf::Text> continueText;
};


#endif //PROJECTAP_PAUSEDSTATE_H
