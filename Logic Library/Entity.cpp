
#include "Entity.h"

Entity::Entity(const pair<float, float> &position) : position(position) {}

const pair<float, float> &Entity::getPosition() const {
    return position;
}

void Entity::setPosition(const pair<float, float> &position) {
    Entity::position = position;
}

const string &Entity::getColor() const {
    return "";
}
