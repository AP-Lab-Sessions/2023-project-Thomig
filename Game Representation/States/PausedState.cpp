//
// Created by thomas on 30/07/24.
//

#include "PausedState.h"

PausedState::PausedState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
    // Blue outline
    background = make_shared<sf::RectangleShape>(sf::Vector2f(1750.0f, 920.0f));
    background->setFillColor(sf::Color::Black);
    background->setPosition(50, 50);
    background->setOutlineColor(sf::Color::Blue);
    background->setOutlineThickness(50);

    // Paused text
    pausedText = make_shared<sf::Text>();
    pausedText->setFont(*font);
    pausedText->setString("Paused");
    pausedText->setCharacterSize(100);
    pausedText->setFillColor(sf::Color::Yellow);
    pausedText->setPosition(1920 / 2 - pausedText->getGlobalBounds().width / 2, 1080 / 2 - pausedText->getGlobalBounds().height / 2);
}

void PausedState::handleEvent(sf::Event &event) {
    shared_ptr<Stats> stats = Stats::getInstance();
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        stateManager->popState();
        stats->switchResetWorldClock();
    }
}

void PausedState::update() {

}

void PausedState::render() {
    // Render
    window->draw(*background);
    window->draw(*pausedText);

    window->display();
}
