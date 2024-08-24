//
// Created by thomas on 30/07/24.
//

#include "MenuState.h"

MenuState::MenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
    auto &camera = Camera::getInstance();

    // blue outline
    int thickness = camera.modelThickness(50);
    background = make_shared<sf::RectangleShape>(
            sf::Vector2f(window->getSize().x - 2 * thickness, window->getSize().y - 2 * thickness));
    background->setFillColor(sf::Color::Black);
    background->setPosition(thickness, thickness);
    background->setOutlineColor(sf::Color::Blue);
    background->setOutlineThickness(thickness);

    // text boxes
    scoreBox = make_shared<sf::RectangleShape>(sf::Vector2f(camera.modelWidth(300), camera.modelHeight(400)));
    scoreBox->setFillColor(sf::Color(64, 64, 64));
    scoreBox->setPosition(camera.modelWidth(780), camera.modelHeight(250));
    scoreBox->setOutlineColor(sf::Color(32, 32, 32));
    scoreBox->setOutlineThickness(camera.modelThickness(10));

    playButton = make_shared<sf::RectangleShape>(sf::Vector2f(camera.modelWidth(300), camera.modelHeight(100)));
    playButton->setFillColor(sf::Color(64, 64, 64));
    playButton->setPosition(camera.modelWidth(780), camera.modelHeight(725));
    playButton->setOutlineColor(sf::Color(32, 32, 32));
    playButton->setOutlineThickness(camera.modelThickness(10));

    playText = make_shared<sf::Text>();
    playText->setFont(*font);
    playText->setString("Play");
    playText->setCharacterSize(thickness);
    playText->setFillColor(sf::Color::Green);
    playText->setPosition(camera.modelWidth(880), camera.modelHeight(740));

    titleText = make_shared<sf::Text>();
    titleText->setFont(*font);
    titleText->setString("Pacman");
    titleText->setCharacterSize(thickness * 2);
    titleText->setFillColor(sf::Color::Yellow);
    titleText->setPosition(camera.modelWidth(740), camera.modelHeight(90));

    creditText = make_shared<sf::Text>();
    creditText->setFont(*font);
    creditText->setString("By Thomas Urkens");
    creditText->setCharacterSize(thickness * 0.5);
    creditText->setFillColor(sf::Color::White);
    creditText->setPosition(camera.modelWidth(1570), camera.modelHeight(920));

    for (int i = 0; i < 5; i++) {
        shared_ptr<sf::Text> text3 = make_shared<sf::Text>();
        text3->setFont(*font);
        text3->setString(to_string(i + 1) + ". " + to_string(Stats::getInstance()->getScoreBoard()[i]));
        text3->setCharacterSize(camera.modelThickness(40));
        text3->setFillColor(sf::Color::Yellow);
        text3->setPosition(camera.modelWidth(860), camera.modelHeight(260) + i * camera.modelHeight(80));
        scoreTexts.push_back(text3);
    }
}

void MenuState::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        stateManager->pushState(std::make_shared<LevelState>(stateManager));
    }
}

void MenuState::handleMouseClick(string button) {
    if (button == "Play") {
        stateManager->pushState(std::make_shared<LevelState>(stateManager));
    }
}

void MenuState::update() {
    // Update menu items
    for (int i = 0; i < 5; i++) {
        scoreTexts[i]->setString(to_string(i + 1) + ". " + to_string(Stats::getInstance()->getScoreBoard()[i]));
    }
}

void MenuState::render() {
    // Render menu items
    window->draw(*background);
    window->draw(*scoreBox);
    window->draw(*playButton);
    window->draw(*titleText);
    window->draw(*playText);
    for (auto &text: scoreTexts) {
        window->draw(*text);
    }
    window->draw(*creditText);

    window->display();
}
