//
// Created by thomas on 4/12/23.
//

#include "MenuState.h"

string MenuState::getType() {
    return "MenuState";
}

MenuState::MenuState() {
    // get top 5 scores
    shared_ptr<LevelStats> levelStats = LevelStats::getInstance();
    vector<int> scores = levelStats->getScoreboard();

    // set font
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    try {
        // check if file is found
        if (!font->loadFromFile("../Arial.ttf")) {
            throw runtime_error("File Arial.ttf is not found or unable to open");
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    shared_ptr<Text> text1 = make_shared<Text>();
    text1->text.setFont(*font);
    text1->text.setString("Pacman");
    text1->text.setCharacterSize(160);
    text1->text.setFillColor(sf::Color::Yellow);
    text1->text.setPosition(650,40);
    text1->text.setOutlineColor(sf::Color(255,165,0));
    text1->text.setOutlineThickness(2);
    texts.push_back(text1);

    shared_ptr<Text> text2 = make_shared<Text>();
    text2->text.setFont(*font);
    text2->text.setString("By Thomas Urkens");
    text2->text.setCharacterSize(18);
    text2->text.setFillColor(sf::Color::White);
    text2->text.setPosition(60,935);
    texts.push_back(text2);

    shared_ptr<Text> text3 = make_shared<Text>();
    text3->text.setFont(*font);
    text3->text.setString("Scoreboard");
    text3->text.setCharacterSize(50);
    text3->text.setFillColor(sf::Color(255,165,0));
    text3->text.setPosition(800,300);
    texts.push_back(text3);

    shared_ptr<Text> text4 = make_shared<Text>();
    text4->text.setFont(*font);
    string s = "1: " + to_string(scores[0]);
    text4->text.setString(s);
    text4->text.setCharacterSize(32);
    text4->text.setFillColor(sf::Color::Yellow);
    text4->text.setPosition(880,370);
    texts.push_back(text4);

    shared_ptr<Text> text5 = make_shared<Text>();
    text5->text.setFont(*font);
    s = "2: " + to_string(scores[1]);
    text5->text.setString(s);
    text5->text.setCharacterSize(32);
    text5->text.setFillColor(sf::Color::Yellow);
    text5->text.setPosition(880,420);
    texts.push_back(text5);

    shared_ptr<Text> text6 = make_shared<Text>();
    text6->text.setFont(*font);
    s = "3: " + to_string(scores[2]);
    text6->text.setString(s);
    text6->text.setCharacterSize(32);
    text6->text.setFillColor(sf::Color::Yellow);
    text6->text.setPosition(880,470);
    texts.push_back(text6);

    shared_ptr<Text> text7 = make_shared<Text>();
    text7->text.setFont(*font);
    s = "4: " + to_string(scores[3]);
    text7->text.setString(s);
    text7->text.setCharacterSize(32);
    text7->text.setFillColor(sf::Color::Yellow);
    text7->text.setPosition(880,520);
    texts.push_back(text7);

    shared_ptr<Text> text8 = make_shared<Text>();
    text8->text.setFont(*font);
    s = "5: " + to_string(scores[4]);
    text8->text.setString(s);
    text8->text.setCharacterSize(32);
    text8->text.setFillColor(sf::Color::Yellow);
    text8->text.setPosition(880,570);
    texts.push_back(text8);

    shared_ptr<Text> text9 = make_shared<Text>();
    text9->text.setFont(*font);
    text9->text.setString("Play");
    text9->text.setCharacterSize(50);
    text9->text.setFillColor(sf::Color::Green);
    text9->text.setPosition(878,738);
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

void MenuState::update() {
}
