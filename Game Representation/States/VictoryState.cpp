//
// Created by thomas on 30/07/24.
//

#include "VictoryState.h"

VictoryState::VictoryState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
    auto &camera = Camera::getInstance();
    int thickness = camera.modelThickness(50);

    background = make_shared<sf::RectangleShape>(
            sf::Vector2f(window->getSize().x - 2 * thickness, window->getSize().y - 2 * thickness));
    background->setFillColor(sf::Color::Black);
    background->setPosition(thickness, thickness);
    background->setOutlineColor(sf::Color::Green);
    background->setOutlineThickness(thickness);

    victoryText = make_shared<sf::Text>();
    victoryText->setFont(*font);
    victoryText->setString("Victory!");
    victoryText->setCharacterSize(thickness * 2);
    victoryText->setFillColor(sf::Color::Yellow);
    victoryText->setPosition(camera.modelWidth(760), camera.modelHeight(90));

    scoreText = make_shared<sf::Text>();
    scoreText->setFont(*font);
    scoreText->setCharacterSize(thickness);
    scoreText->setString("Score: " + to_string(Stats::getInstance()->getScore()));
    scoreText->setFillColor(sf::Color::Yellow);
    scoreText->setPosition(camera.modelWidth(805), camera.modelHeight(450));
}

void VictoryState::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        stateManager->popState();
        stateManager->popState();
        stateManager->pushState(std::make_shared<LevelState>(stateManager));
    }
}

void VictoryState::handleMouseClick(string button) {}

void VictoryState::update() {
    scoreText->setString("Score: " + to_string(Stats::getInstance()->getScore()));
}

void VictoryState::render() {
    window->draw(*background);
    window->draw(*victoryText);
    window->draw(*scoreText);

    window->display();
}
