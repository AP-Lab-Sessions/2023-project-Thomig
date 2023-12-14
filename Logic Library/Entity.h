#ifndef PROJECTAP_ENTITY_H
#define PROJECTAP_ENTITY_H

#include "utility"
#include "string"
#include "vector"

using namespace std;

class Entity {
public:
    virtual string getType() = 0;

    explicit Entity(const pair<float, float> &position);

    [[nodiscard]] const pair<float, float> &getPosition() const;

    // returns hitbox: {topLeftX, topLeftY, bottomRightX, bottomRightY}
    virtual vector<float> getHitbox() = 0;

private:
    pair<float,float> position;
};


#endif //PROJECTAP_ENTITY_H
