//
// Created by thomas on 31/07/24.
//

#ifndef PROJECTAP_GAMEOVERSTATE_H
#define PROJECTAP_GAMEOVERSTATE_H

#include "../State.h"
#include "../StateManager.h"

class GameOverState: public State {
public:
    GameOverState(shared_ptr<StateManager> stateManager);

    void handleEvent(sf::Event& event) override;

    void update() override;

    void render() override;

private:
    shared_ptr<sf::Shape> background;
    shared_ptr<sf::Text> gameOverText;
    shared_ptr<sf::Text> scoreText;
};


#endif //PROJECTAP_GAMEOVERSTATE_H
