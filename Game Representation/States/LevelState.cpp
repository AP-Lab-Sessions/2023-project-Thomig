//
// Created by thomas on 4/12/23.
//

#include "LevelState.h"

string LevelState::getType() {
    return "LevelState";
}

LevelState::LevelState(int lives, int score) {
    world = make_shared<World>(World());
    world->setLives(lives);
    shared_ptr<Score> score1 = make_shared<Score>();
    score1->add(score);
    world->setScore(score1);
    camera = make_shared<Camera>(Camera());
    shapes = camera->shapeProjection(world);
}

bool LevelState::update(const string& direction, bool check) {
    texts = camera->textProjection(world);
    sprites = camera->spriteProjection(world);
    return world->update(direction, check);
}

bool LevelState::levelFinished() {
    return world->levelFinished();
}
