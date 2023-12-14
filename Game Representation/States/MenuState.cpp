//
// Created by thomas on 4/12/23.
//

#include "MenuState.h"

string MenuState::getType() {
    return "MenuState";
}

const vector<shared_ptr<sf::Shape>> &MenuState::getShapes() const {
    return shapes;
}

const vector<shared_ptr<sf::Text>> &MenuState::getTexts() const {
    return texts;
}

const vector<shared_ptr<sf::Sprite>> &MenuState::getSprites() const {
    return sprites;
}

MenuState::MenuState() {
    // get top 5 scores
    Score score;
    vector<int> scores = score.getScoreBoard();

    // set font
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    if (!font->loadFromFile("../Arial.ttf")) {
        // Handle font loading error
        // return EXIT_FAILURE;
    }

    shared_ptr<sf::Text> text1 = make_shared<sf::Text>();
    text1->setFont(*font);
    text1->setString("Pacman");
    text1->setCharacterSize(160);
    text1->setFillColor(sf::Color::Yellow);
    text1->setPosition(650,40);
    text1->setOutlineColor(sf::Color(255,165,0));
    text1->setOutlineThickness(2);
    texts.push_back(text1);

    shared_ptr<sf::Text> text2 = make_shared<sf::Text>();
    text2->setFont(*font);
    text2->setString("By Thomas Urkens");
    text2->setCharacterSize(18);
    text2->setFillColor(sf::Color::White);
    text2->setPosition(60,935);
    texts.push_back(text2);

    shared_ptr<sf::Text> text3 = make_shared<sf::Text>();
    text3->setFont(*font);
    text3->setString("Scoreboard");
    text3->setCharacterSize(50);
    text3->setFillColor(sf::Color(255,165,0));
    text3->setPosition(800,300);
    texts.push_back(text3);

    shared_ptr<sf::Text> text4 = make_shared<sf::Text>();
    text4->setFont(*font);
    string s = "1: " + to_string(scores[0]);
    text4->setString(s);
    text4->setCharacterSize(32);
    text4->setFillColor(sf::Color::Yellow);
    text4->setPosition(880,370);
    texts.push_back(text4);

    shared_ptr<sf::Text> text5 = make_shared<sf::Text>();
    text5->setFont(*font);
    s = "2: " + to_string(scores[1]);
    text5->setString(s);
    text5->setCharacterSize(32);
    text5->setFillColor(sf::Color::Yellow);
    text5->setPosition(880,420);
    texts.push_back(text5);

    shared_ptr<sf::Text> text6 = make_shared<sf::Text>();
    text6->setFont(*font);
    s = "3: " + to_string(scores[2]);
    text6->setString(s);
    text6->setCharacterSize(32);
    text6->setFillColor(sf::Color::Yellow);
    text6->setPosition(880,470);
    texts.push_back(text6);

    shared_ptr<sf::Text> text7 = make_shared<sf::Text>();
    text7->setFont(*font);
    s = "4: " + to_string(scores[3]);
    text7->setString(s);
    text7->setCharacterSize(32);
    text7->setFillColor(sf::Color::Yellow);
    text7->setPosition(880,520);
    texts.push_back(text7);

    shared_ptr<sf::Text> text8 = make_shared<sf::Text>();
    text8->setFont(*font);
    s = "5: " + to_string(scores[4]);
    text8->setString(s);
    text8->setCharacterSize(32);
    text8->setFillColor(sf::Color::Yellow);
    text8->setPosition(880,570);
    texts.push_back(text8);

    shared_ptr<sf::Text> text9 = make_shared<sf::Text>();
    text9->setFont(*font);
    text9->setString("Play");
    text9->setCharacterSize(50);
    text9->setFillColor(sf::Color::Green);
    text9->setPosition(878,738);
    texts.push_back(text9);

    shared_ptr<sf::Shape> shape1 = make_shared<sf::RectangleShape>(sf::Vector2f(1750.0f, 920.0f));
    shape1->setFillColor(sf::Color::Black);
    shape1->setPosition(50,50);
    shape1->setOutlineColor(sf::Color::Blue);
    shape1->setOutlineThickness(50);
    shapes.push_back(shape1);

    shared_ptr<sf::Shape> shape2 = make_shared<sf::RectangleShape>(sf::Vector2f(300.0f, 400.0f));
    shape2->setFillColor(sf::Color(64,64,64));
    shape2->setPosition(780,250);
    shape2->setOutlineColor(sf::Color(32,32,32));
    shape2->setOutlineThickness(10);
    shapes.push_back(shape2);

    shared_ptr<sf::Shape> shape3 = make_shared<sf::RectangleShape>(sf::Vector2f(300.0f, 100.0f));
    shape3->setFillColor(sf::Color(64,64,64));
    shape3->setPosition(780,725);
    shape3->setOutlineColor(sf::Color(32,32,32));
    shape3->setOutlineThickness(10);
    shapes.push_back(shape3);
}

void MenuState::update(const string &direction) {}
