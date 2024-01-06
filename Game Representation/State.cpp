//
// Created by thomas on 4/12/23.
//

#include "State.h"

const vector<shared_ptr<sf::Shape>> &State::getShapes() const {
    return shapes;
}

const vector<shared_ptr<Text>> &State::getTexts() const {
    return texts;
}

const vector<shared_ptr<Sprite>> &State::getSprites() const {
    return sprites;
}

bool State::update(const string &direction, bool check) {
    return false;
}

bool State::levelFinished() {
    return false;
}

void State::update() {

}
