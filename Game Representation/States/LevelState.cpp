//
// Created by thomas on 4/12/23.
//

#include "LevelState.h"

string LevelState::getType() {
    return "LevelState";
}

const vector<shared_ptr<sf::Shape>> &LevelState::getShapes() const {
    return shapes;
}

const vector<shared_ptr<sf::Text>> &LevelState::getTexts() const {
    return texts;
}

const vector<shared_ptr<sf::Sprite>> &LevelState::getSprites() const {
    return sprites;
}

LevelState::LevelState() {
    world = make_shared<World>(World());
    camera = make_shared<Camera>(Camera());
}

void LevelState::update(const string& direction) {
    shapes = camera->shapeProjection(world);
    sprites = camera->spriteProjection(world);
}
