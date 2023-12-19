#include "Pacman.h"

string Pacman::getType() {
    return "Pacman";
}

Pacman::Pacman(const pair<float, float> &position) : Entity(position) {}

vector<float> Pacman::getHitbox() {
    float x = 0.027;  // size of hitbox in every direction of position
    return {getPosition().first-x, getPosition().second+x, getPosition().first+x, getPosition().second-x};
}
