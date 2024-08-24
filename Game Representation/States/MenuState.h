//
// Created by thomas on 30/07/24.
//

#ifndef PROJECTAP_MENUSTATE_H
#define PROJECTAP_MENUSTATE_H

#include "../State.h"
#include "../StateManager.h"
#include "LevelState.h"

class MenuState : public State {
public:
    MenuState(std::shared_ptr<StateManager> stateManager);

    void handleEvent(sf::Event &event) override;

    void handleMouseClick(string button) override;

    void update() override;

    void render() override;

private:
    shared_ptr<sf::Text> titleText;
    shared_ptr<sf::Text> playText;
    vector<shared_ptr<sf::Text>> scoreTexts;
    shared_ptr<sf::Shape> background;
    shared_ptr<sf::Shape> playButton;
    shared_ptr<sf::Shape> scoreBox;
    shared_ptr<sf::Text> creditText;
};

#endif //PROJECTAP_MENUSTATE_H
