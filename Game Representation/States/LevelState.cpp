//
// Created by thomas on 30/07/24.
//

#include "LevelState.h"

LevelState::LevelState(std::shared_ptr<StateManager> stateManager) : State(stateManager) {
    Camera &camera = Camera::getInstance();
    int thickness = camera.modelThickness(50);

    // Load texts
    scoreText = make_shared<sf::Text>();
    scoreText->setFont(*font);
    scoreText->setCharacterSize(thickness);
    scoreText->setFillColor(sf::Color::Yellow);
    scoreText->setPosition(camera.modelWidth(380), camera.modelHeight(800));

    difficultyText = make_shared<sf::Text>();
    difficultyText->setFont(*font);
    difficultyText->setCharacterSize(thickness);
    difficultyText->setFillColor(sf::Color::Yellow);
    difficultyText->setPosition(camera.modelWidth(800), camera.modelHeight(800));

    LivesText = make_shared<sf::Text>();
    LivesText->setFont(*font);
    LivesText->setCharacterSize(thickness);
    LivesText->setFillColor(sf::Color::Yellow);
    LivesText->setPosition(camera.modelWidth(1250), camera.modelHeight(800));

    fpsText = make_shared<sf::Text>();
    fpsText->setFont(*font);
    fpsText->setCharacterSize(thickness * 0.5);
    fpsText->setFillColor(sf::Color::Green);
    fpsText->setPosition(camera.modelWidth(1720), camera.modelHeight(10));

    // Create world
    world = make_shared<World>(stateManager->getFactory());
}

void LevelState::handleEvent(sf::Event &event) {
    shared_ptr<Stats> stats = Stats::getInstance();

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        stateManager->pushState(std::make_shared<PausedState>(stateManager));
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left or
                                                      event.type == sf::Event::KeyPressed &&
               event.key.code == sf::Keyboard::A) {
        direction = Left;
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right or
                                                      event.type == sf::Event::KeyPressed &&
               event.key.code == sf::Keyboard::D) {
        direction = Right;
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up or
                                                      event.type == sf::Event::KeyPressed &&
               event.key.code == sf::Keyboard::W) {
        direction = Up;
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down or
                                                      event.type == sf::Event::KeyPressed &&
               event.key.code == sf::Keyboard::S) {
        direction = Down;
    }
}

void LevelState::handleMouseClick(string button) {}

void LevelState::update() {
    shared_ptr<Stats> stats = Stats::getInstance();
    if (stats.get()->getLives() == 0) {
        stateManager->pushState(make_shared<GameOverState>(stateManager));
        return;
    } else if (stats->isLevelCompleted()) {
        stateManager->pushState(make_shared<VictoryState>(stateManager));
        stats->changeLevelCompleted();
        return;
    }

    string s = "Score: " + to_string(stats->getScore());
    scoreText->setString(s);

    string d = "Difficulty: " + to_string(stats->getDifficulty());
    difficultyText->setString(d);

    string l = "Lives: " + to_string(stats->getLives());
    LivesText->setString(l);

    string fps = "FPS: " + to_string(stats->getFps());
    fpsText->setString(fps);

    world->update(direction);
}

void LevelState::render() {
    window->draw(*scoreText);
    window->draw(*difficultyText);
    window->draw(*LivesText);
    window->draw(*fpsText);
}
