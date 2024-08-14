//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_LEVELSTATE_H
#define PROJECTAP_LEVELSTATE_H

#include "../State.h"
#include "../StateManager.h"
#include "PausedState.h"
#include "GameOverState.h"
#include "VictoryState.h"

class LevelState : public State {
public:
    LevelState(std::shared_ptr<StateManager> stateManager);

    void handleEvent(sf::Event& event) override;

    void update() override;

    void render() override;

private:
    shared_ptr<World> world;
    Direction direction = Left;  // Starting pacman direction
    shared_ptr<sf::Text> scoreText;
    shared_ptr<sf::Text> difficultyText;
    shared_ptr<sf::Text> LivesText;
};



#endif //PROJECTAP_LEVELSTATE_H
