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

    int lastSwitched = 0;   // cooldown for ghost direction switch to prevent being stuck in large spaces

    int spawn = 0;  // to check if ghost is dead and make sure it leaves starting box

    int state = 0;  // which sprite to use

    bool isEaten = false;

    int fear = 0;

    int lastDead = 0;

    pair<float,float> positionSave;

private:
    pair<float,float> position;
};


#endif //PROJECTAP_ENTITY_H
