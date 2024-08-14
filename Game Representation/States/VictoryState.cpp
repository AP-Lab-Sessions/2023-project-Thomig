//
// Created by thomas on 30/07/24.
//

#include "VictoryState.h"

VictoryState::VictoryState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
    background = make_shared<sf::RectangleShape>(sf::Vector2f(1750.0f, 920.0f));
    background->setFillColor(sf::Color::Black);
    background->setPosition(50, 50);
    background->setOutlineColor(sf::Color::Green);
    background->setOutlineThickness(50);

    victoryText = std::make_shared<sf::Text>("Victory!", *font, 50);
    victoryText->setFillColor(sf::Color::Yellow);
    victoryText->setPosition(300, 200);

    scoreText = std::make_shared<sf::Text>("Score: 0", *font, 30);
    scoreText->setFillColor(sf::Color::Yellow);
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
    scoreText->setString("Score: " + to_string(Stats::getInstance()->getScore()));
}

void VictoryState::render() {
    window->draw(*background);
    window->draw(*victoryText);
    window->draw(*scoreText);

    window->display();
}
