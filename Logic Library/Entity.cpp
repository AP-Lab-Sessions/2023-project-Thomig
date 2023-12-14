
#include "Entity.h"

Entity::Entity(const pair<float, float> &position) : position(position) {}

const pair<float, float> &Entity::getPosition() const {
    return position;
}
