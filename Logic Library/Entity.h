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

    void setPosition(const pair<float, float> &position);

    // returns hitbox: {topLeftX, topLeftY, bottomRightX, bottomRightY}
    virtual vector<float> getHitbox() = 0;

    virtual const string &getColor() const;

    string moving = "Left";

    int state = 0;  // which sprite to use

    bool isEaten = false;

    int fear = 0;   // fear timer (0 = no fear mode)

private:
    pair<float, float> position;
};


#endif //PROJECTAP_ENTITY_H
