//
// Created by thomas on 30/07/24.
//

#include "MenuState.h"

MenuState::MenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {}

void MenuState::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        stateManager->pushState(std::make_shared<LevelState>(stateManager));
    }
}

void MenuState::update() {
    // Update menu items
}

void MenuState::render() {
    // Render menu items
    sf::Text text;
    text.setFont(*font);
    text.setString("Play");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(1920 / 2 - text.getGlobalBounds().width / 2, 1080 / 2 - text.getGlobalBounds().height / 2);
    window->draw(text);

    // blue outline
    shared_ptr<sf::Shape> shape1 = make_shared<sf::RectangleShape>(sf::Vector2f(1750.0f, 920.0f));
    shape1->setFillColor(sf::Color::Black);
    shape1->setPosition(50, 50);
    shape1->setOutlineColor(sf::Color::Blue);
    shape1->setOutlineThickness(50);
    window->draw(*shape1);

    // text boxes
    shared_ptr<sf::Shape> shape2 = make_shared<sf::RectangleShape>(sf::Vector2f(300.0f, 400.0f));
    shape2->setFillColor(sf::Color(64, 64, 64));
    shape2->setPosition(780, 250);
    shape2->setOutlineColor(sf::Color(32, 32, 32));
    shape2->setOutlineThickness(10);
    window->draw(*shape2);

    shared_ptr<sf::Shape> shape3 = make_shared<sf::RectangleShape>(sf::Vector2f(300.0f, 100.0f));
    shape3->setFillColor(sf::Color(64, 64, 64));
    shape3->setPosition(780, 725);
    shape3->setOutlineColor(sf::Color(32, 32, 32));
    shape3->setOutlineThickness(10);
    window->draw(*shape3);

    shared_ptr<sf::Text> text1 = make_shared<sf::Text>();
    text1->setFont(*font);
    text1->setString("Play");
    text1->setCharacterSize(50);
    text1->setFillColor(sf::Color::Green);
    text1->setPosition(878, 738);
    window->draw(*text1);

    for (int i = 0; i < 5; i++) {
        shared_ptr<sf::Text> text2 = make_shared<sf::Text>();
        text2->setFont(*font);
        text2->setString(to_string(i + 1) + ". " + to_string(Stats::getInstance()->getScoreBoard()[i]));
        text2->setCharacterSize(40);
        text2->setFillColor(sf::Color::Yellow);
        text2->setPosition(830, 260 + i * 80);
        window->draw(*text2);
    }

    window->display();
}
