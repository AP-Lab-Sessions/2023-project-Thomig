//
// Created by thomas on 11/12/23.
//

#ifndef PROJECTAP_WALL_H
#define PROJECTAP_WALL_H

#include "../Entity.h"

class Wall: public Entity{
public:
    string getType() override;

    explicit Wall(const pair<float, float> &position);

    vector<float> getHitbox() override;
};


#endif //PROJECTAP_WALL_H
