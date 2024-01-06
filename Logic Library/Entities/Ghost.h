//
// Created by thomas on 11/12/23.
//

#ifndef PROJECTAP_GHOST_H
#define PROJECTAP_GHOST_H

#include "../Entity.h"

class Ghost: public Entity{
public:
    string getType() override;

    Ghost(const pair<float, float> &position, const string &color);

    [[nodiscard]] const string &getColor() const override;

    vector<float> getHitbox() override;

    vector<float> getSmallHitbox();

    bool chaseMode = false;

    int lastSwitched = 0;   // cooldown for ghost direction switch to prevent being stuck in large spaces

    int spawn = 0;  // to check if ghost is dead and make sure it leaves starting box

    int lastDead = 0;

    pair<float,float> positionSave;

private:
    string color;
};


#endif //PROJECTAP_GHOST_H
