//
// Created by thomas on 30/07/24.
//

#include "LevelState.h"

LevelState::LevelState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
    // Load font
    font = std::make_shared<sf::Font>();
    try {
        // check if file is found
        if (!font->loadFromFile("../Arial.ttf")) {
            throw runtime_error("File Arial.ttf is not found or unable to open");
        }
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Load texts
    scoreText = make_shared<sf::Text>();
    scoreText->setFont(*font);
    scoreText->setCharacterSize(48);
    scoreText->setFillColor(sf::Color::Yellow);
    scoreText->setPosition(450 - scoreText->getGlobalBounds().width / 2, 820 - scoreText->getGlobalBounds().height / 2);

    difficultyText = make_shared<sf::Text>();
    difficultyText->setFont(*font);
    difficultyText->setCharacterSize(48);
    difficultyText->setFillColor(sf::Color::Yellow);
    difficultyText->setPosition(800 - difficultyText->getGlobalBounds().width / 2, 820 - difficultyText->getGlobalBounds().height / 2);

    LivesText = make_shared<sf::Text>();
    LivesText->setFont(*font);
    LivesText->setCharacterSize(48);
    LivesText->setFillColor(sf::Color::Yellow);
    LivesText->setPosition(1200 - LivesText->getGlobalBounds().width / 2, 820 - LivesText->getGlobalBounds().height / 2);

    // Create world
    world = World(stateManager->getFactory());
}

void LevelState::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        stateManager->pushState(std::make_shared<PausedState>(stateManager));
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left or
             event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
        direction = Left;
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right or
             event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
        direction = Right;
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up or
             event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) {
        direction = Up;
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down or
             event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
        direction = Down;
    }
}

void LevelState::update() {
    shared_ptr<Stats> stats = Stats::getInstance();
    string s = "Score: " + to_string(stats->getScore());
    scoreText->setString(s);
    world.update(direction);

    string d = "Difficulty: " + to_string(stats->getDifficulty());
    difficultyText->setString(d);
    world.update(direction);

    string l = "Lives: " + to_string(stats->getLives());
    LivesText->setString(l);
}

void LevelState::render() {
    window->draw(*scoreText);
    window->draw(*difficultyText);
    window->draw(*LivesText);
}
