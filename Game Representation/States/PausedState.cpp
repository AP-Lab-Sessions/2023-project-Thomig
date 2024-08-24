//
// Created by thomas on 30/07/24.
//

#include "PausedState.h"

PausedState::PausedState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
    auto &camera = Camera::getInstance();
    int thickness = camera.modelThickness(50);

    // Blue outline
    background = make_shared<sf::RectangleShape>(
            sf::Vector2f(window->getSize().x - 2 * thickness, window->getSize().y - 2 * thickness));
    background->setFillColor(sf::Color::Black);
    background->setPosition(thickness, thickness);
    background->setOutlineColor(sf::Color::Blue);
    background->setOutlineThickness(thickness);

    // Paused text
    pausedText = make_shared<sf::Text>();
    pausedText->setFont(*font);
    pausedText->setString("Paused");
    pausedText->setCharacterSize(thickness * 2);
    pausedText->setFillColor(sf::Color::Yellow);
    pausedText->setPosition(camera.modelWidth(760), camera.modelHeight(90));

    // Buttons
    homeButton = make_shared<sf::RectangleShape>(sf::Vector2f(camera.modelWidth(300), camera.modelHeight(100)));
    homeButton->setFillColor(sf::Color(64, 64, 64));
    homeButton->setPosition(camera.modelWidth(780), camera.modelHeight(525));
    homeButton->setOutlineColor(sf::Color(32, 32, 32));
    homeButton->setOutlineThickness(camera.modelThickness(10));

    continueButton = make_shared<sf::RectangleShape>(sf::Vector2f(camera.modelWidth(300), camera.modelHeight(100)));
    continueButton->setFillColor(sf::Color(64, 64, 64));
    continueButton->setPosition(camera.modelWidth(780), camera.modelHeight(375));
    continueButton->setOutlineColor(sf::Color(32, 32, 32));
    continueButton->setOutlineThickness(camera.modelThickness(10));

    continueText = make_shared<sf::Text>();
    continueText->setFont(*font);
    continueText->setString("Continue");
    continueText->setCharacterSize(thickness);
    continueText->setFillColor(sf::Color::Green);
    continueText->setPosition(camera.modelWidth(835), camera.modelHeight(390));

    homeText = make_shared<sf::Text>();
    homeText->setFont(*font);
    homeText->setString("Home");
    homeText->setCharacterSize(thickness);
    homeText->setFillColor(sf::Color::Red);
    homeText->setPosition(camera.modelWidth(865), camera.modelHeight(540));
}

void PausedState::handleEvent(sf::Event &event) {
    shared_ptr<Stats> stats = Stats::getInstance();
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        stateManager->popState();
        stats->switchResetWorldClock();
    }
}

void PausedState::handleMouseClick(string button) {
    shared_ptr<Stats> stats = Stats::getInstance();
    if (button == "Continue") {
        stateManager->popState();
        stats->switchResetWorldClock();
    } else if (button == "Home") {
        stateManager->popState();
        stateManager->popState();
        stats->resetStats();
    }
}

void PausedState::update() {

}

void PausedState::render() {
    // Render
    window->draw(*background);
    window->draw(*pausedText);
    window->draw(*continueButton);
    window->draw(*continueText);
    window->draw(*homeButton);
    window->draw(*homeText);

    window->display();
}
