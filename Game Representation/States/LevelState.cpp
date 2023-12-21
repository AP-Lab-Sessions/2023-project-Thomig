//
// Created by thomas on 4/12/23.
//

#include "LevelState.h"

string LevelState::getType() {
    return "LevelState";
}

LevelState::LevelState() {
    world = make_shared<World>(World());
    shared_ptr<Score> score1 = make_shared<Score>();
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

bool LevelState::levelDead() {
    return world->levelDead();
}
