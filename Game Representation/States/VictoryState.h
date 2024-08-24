//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_VICTORYSTATE_H
#define PROJECTAP_VICTORYSTATE_H

#include "../State.h"
#include "../StateManager.h"
#include "LevelState.h"

class VictoryState : public State {
public:
    VictoryState(std::shared_ptr<StateManager> stateManager);

    void handleEvent(sf::Event &event) override;

    void handleMouseClick(string button) override;

    void update() override;

    void render() override;

private:
    shared_ptr<sf::Shape> background;
    shared_ptr<sf::Text> victoryText;
    shared_ptr<sf::Text> scoreText;
};


#endif //PROJECTAP_VICTORYSTATE_H
