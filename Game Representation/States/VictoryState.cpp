//
// Created by thomas on 30/07/24.
//

#include "VictoryState.h"

VictoryState::VictoryState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
    background = std::make_shared<sf::RectangleShape>(sf::Vector2f(800, 600));
    background->setFillColor(sf::Color::Green);

    victoryText = std::make_shared<sf::Text>("Victory!", *font, 50);
    victoryText->setFillColor(sf::Color::Black);
    victoryText->setPosition(300, 200);

    scoreText = std::make_shared<sf::Text>("Score: 0", *font, 30);
    scoreText->setFillColor(sf::Color::Black);
    scoreText->setPosition(300, 300);
}

void VictoryState::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        stateManager->popState();
        stateManager->popState();
        stateManager->pushState(std::make_shared<LevelState>(stateManager));
    }
}

void VictoryState::update() {

}

void VictoryState::render() {
    window->draw(*background);
    window->draw(*victoryText);
    window->draw(*scoreText);

    window->display();
}
