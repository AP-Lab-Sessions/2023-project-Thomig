//
// Created by thomas on 5/12/23.
//

#include "GameOverState.h"

string GameOverState::getType() {
    return "GameOverState";
}

const vector<shared_ptr<sf::Shape>> &GameOverState::getShapes() const {
    return shapes;
}

const vector<shared_ptr<sf::Text>> &GameOverState::getTexts() const {
    return texts;
}

const vector<shared_ptr<sf::Sprite>> &GameOverState::getSprites() const {
    return sprites;
}

GameOverState::GameOverState() {

}

void GameOverState::update(const string &direction) {}
