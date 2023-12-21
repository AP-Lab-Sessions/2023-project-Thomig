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

    bool chaseMode = false;

private:
    string color;
};


#endif //PROJECTAP_GHOST_H
