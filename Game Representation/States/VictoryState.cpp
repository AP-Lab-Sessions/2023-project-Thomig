//
// Created by thomas on 4/12/23.
//

#include "VictoryState.h"

string VictoryState::getType() {
    return "VictoryState";
}

const vector<shared_ptr<sf::Shape>> &VictoryState::getShapes() const {
    return shapes;
}

const vector<shared_ptr<sf::Text>> &VictoryState::getTexts() const {
    return texts;
}

const vector<shared_ptr<sf::Sprite>> &VictoryState::getSprites() const {
    return sprites;
}

VictoryState::VictoryState() {

}

void VictoryState::update(const string &direction) {}
