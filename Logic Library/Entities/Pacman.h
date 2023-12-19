#ifndef PROJECTAP_PACMAN_H
#define PROJECTAP_PACMAN_H

#include "../Entity.h"

class Pacman: public Entity{
public:
    string getType() override;

    explicit Pacman(const pair<float, float> &position);

    vector<float> getHitbox() override;

};


#endif //PROJECTAP_PACMAN_H
