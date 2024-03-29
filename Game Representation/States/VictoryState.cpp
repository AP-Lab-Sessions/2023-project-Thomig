//
// Created by thomas on 4/12/23.
//

#include "VictoryState.h"

string VictoryState::getType() {
    return "VictoryState";
}

VictoryState::VictoryState() {
    // set font
    shared_ptr<Text> text1 = make_shared<Text>();
    try {
        // check if file is found
        if (!text1->font.loadFromFile("../Arial.ttf")) {
            throw runtime_error("File Arial.ttf is not found or unable to open");
        }
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    text1->text.setFont(text1->font);
    text1->text.setString("Victory!");
    text1->text.setCharacterSize(160);
    text1->text.setFillColor(sf::Color::Yellow);
    text1->text.setPosition(650, 240);
    text1->text.setOutlineColor(sf::Color(255, 165, 0));
    text1->text.setOutlineThickness(2);
    texts.push_back(text1);

    shared_ptr<sf::Shape> shape1 = make_shared<sf::RectangleShape>(sf::Vector2f(1750.0f, 920.0f));
    shape1->setFillColor(sf::Color::Black);
    shape1->setPosition(50, 50);
    shape1->setOutlineColor(sf::Color::Blue);
    shape1->setOutlineThickness(50);
    shapes.push_back(shape1);
}
