//
// Created by thomas on 30/07/24.
//

#include "PausedState.h"

PausedState::PausedState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {}

void PausedState::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        stateManager->popState();
    }
}

void PausedState::update(float deltaTime) {
    // Update game logic
}

void PausedState::render(sf::RenderWindow &window) {
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    try {
        // check if file is found
        if (!font->loadFromFile("../Arial.ttf")) {
            throw runtime_error("File Arial.ttf is not found or unable to open");
        }
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    // blue outline
    shared_ptr<sf::Shape> shape1 = make_shared<sf::RectangleShape>(sf::Vector2f(1750.0f, 920.0f));
    shape1->setFillColor(sf::Color::Black);
    shape1->setPosition(50, 50);
    shape1->setOutlineColor(sf::Color::Blue);
    shape1->setOutlineThickness(50);
    window.draw(*shape1);

    window.display();
}
