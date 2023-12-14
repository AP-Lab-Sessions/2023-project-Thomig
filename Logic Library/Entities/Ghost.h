//
// Created by thomas on 11/12/23.
//

#ifndef PROJECTAP_GHOST_H
#define PROJECTAP_GHOST_H

#include "../Entity.h"

class Ghost: public Entity{
public:
    string color;
    bool fear = false;

    string getType() override;

    explicit Ghost(const pair<float, float> &position, const string &color);
};


#endif //PROJECTAP_GHOST_H
