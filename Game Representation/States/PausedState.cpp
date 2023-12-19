//
// Created by thomas on 4/12/23.
//

#include "PausedState.h"

string PausedState::getType() {
    return "PausedState";
}

PausedState::PausedState() {
    // set font
    shared_ptr<Text> text1 = make_shared<Text>();
    if (!text1->font.loadFromFile("../Arial.ttf")) {
        // Handle font loading error
        // return EXIT_FAILURE;
        cout << "Error" << endl;
    }

    text1->text.setFont(text1->font);
    text1->text.setString("Paused");
    text1->text.setCharacterSize(160);
    text1->text.setFillColor(sf::Color::Yellow);
    text1->text.setPosition(650,240);
    text1->text.setOutlineColor(sf::Color(255,165,0));
    text1->text.setOutlineThickness(2);
    texts.push_back(text1);

    shared_ptr<sf::Shape> shape1 = make_shared<sf::RectangleShape>(sf::Vector2f(1750.0f, 920.0f));
    shape1->setFillColor(sf::Color::Black);
    shape1->setPosition(50,50);
    shape1->setOutlineColor(sf::Color::Blue);
    shape1->setOutlineThickness(50);
    shapes.push_back(shape1);
}
