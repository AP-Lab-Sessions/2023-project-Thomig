//
// Created by thomas on 4/12/23.
//

#include "PausedState.h"

string PausedState::getType() {
    return "PausedState";
}

const vector<shared_ptr<sf::Shape>> &PausedState::getShapes() const {
    return shapes;
}

const vector<shared_ptr<sf::Text>> &PausedState::getTexts() const {
    return texts;
}

const vector<shared_ptr<sf::Sprite>> &PausedState::getSprites() const {
    return sprites;
}

PausedState::PausedState() {
    // set font
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    if (!font->loadFromFile("../Arial.ttf")) {
        // Handle font loading error
        // return EXIT_FAILURE;
    }

    //shared_ptr<sf::Text> text1 = make_shared<sf::Text>();
    //text1->setFont(*font);
    //text1->setString("Paused");
    //text1->setCharacterSize(160);
    //text1->setFillColor(sf::Color::Yellow);
    //text1->setPosition(650,40);
    //text1->setOutlineColor(sf::Color(255,165,0));
    //text1->setOutlineThickness(2);
    //texts.push_back(text1);

    shared_ptr<sf::Shape> shape1 = make_shared<sf::RectangleShape>(sf::Vector2f(1750.0f, 920.0f));
    shape1->setFillColor(sf::Color::Black);
    shape1->setPosition(50,50);
    shape1->setOutlineColor(sf::Color::Blue);
    shape1->setOutlineThickness(50);
    shapes.push_back(shape1);
}

void PausedState::update(const string &direction) {}
