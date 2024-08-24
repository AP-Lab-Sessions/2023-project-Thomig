//
// Created by thomas on 31/07/24.
//

#include "GameOverState.h"

GameOverState::GameOverState(shared_ptr<StateManager> stateManager) : State(stateManager) {
    Camera &camera = Camera::getInstance();
    int thickness = camera.modelThickness(50);

    // Red outline
    background = make_shared<sf::RectangleShape>(
            sf::Vector2f(window->getSize().x - 2 * thickness, window->getSize().y - 2 * thickness));
    background->setFillColor(sf::Color::Black);
    background->setPosition(thickness, thickness);
    background->setOutlineColor(sf::Color::Red);
    background->setOutlineThickness(thickness);

    // Game over text
    gameOverText = make_shared<sf::Text>();
    gameOverText->setFont(*font);
    gameOverText->setString("Game Over");
    gameOverText->setCharacterSize(thickness * 2);
    gameOverText->setFillColor(sf::Color::Red);
    gameOverText->setPosition(camera.modelWidth(675), camera.modelHeight(150));

    // Score text
    scoreText = make_shared<sf::Text>();
    scoreText->setFont(*font);
    scoreText->setCharacterSize(thickness);
    scoreText->setString("Score: " + to_string(Stats::getInstance()->getScore()));
    scoreText->setFillColor(sf::Color::Yellow);
    scoreText->setPosition(camera.modelWidth(835), camera.modelHeight(450));
}

void GameOverState::handleEvent(sf::Event &event) {
    shared_ptr<Stats> stats = Stats::getInstance();
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        stateManager->popState();
        stateManager->popState();
        stats->resetStats();
    }
}

void GameOverState::handleMouseClick(string button) {}

void GameOverState::update() {

}

void GameOverState::render() {
    // Render
    window->draw(*background);
    window->draw(*gameOverText);
    window->draw(*scoreText);

    window->display();
}
