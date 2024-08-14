//
// Created by thomas on 31/07/24.
//

#include "GameOverState.h"

GameOverState::GameOverState(shared_ptr<StateManager> stateManager) : State(stateManager) {
    // Blue outline
    background = make_shared<sf::RectangleShape>(sf::Vector2f(1750.0f, 920.0f));
    background->setFillColor(sf::Color::Black);
    background->setPosition(50, 50);
    background->setOutlineColor(sf::Color::Red);
    background->setOutlineThickness(50);

    // Paused text
    gameOverText = make_shared<sf::Text>();
    gameOverText->setFont(*font);
    gameOverText->setString("Game Over");
    gameOverText->setCharacterSize(100);
    gameOverText->setFillColor(sf::Color::Yellow);
    gameOverText->setPosition(1920 / 2 - gameOverText->getGlobalBounds().width / 2, 1080 / 2 - gameOverText->getGlobalBounds().height / 2);

    // Score text
    scoreText = make_shared<sf::Text>();
    scoreText->setFont(*font);
    scoreText->setCharacterSize(48);
    scoreText->setString("Score: " + to_string(Stats::getInstance()->getScore()));
    scoreText->setFillColor(sf::Color::Yellow);
    scoreText->setPosition(450 - scoreText->getGlobalBounds().width / 2, 820 - scoreText->getGlobalBounds().height / 2);
}

void GameOverState::handleEvent(sf::Event &event) {
    shared_ptr<Stats> stats = Stats::getInstance();
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        stateManager->popState();
        stateManager->popState();
        stats->resetStats();
    }
}

void GameOverState::update() {

}

void GameOverState::render() {
    // Render
    window->draw(*background);
    window->draw(*gameOverText);
    window->draw(*scoreText);

    window->display();
}
