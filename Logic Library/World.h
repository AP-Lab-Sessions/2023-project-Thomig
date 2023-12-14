#ifndef PROJECTAP_WORLD_H
#define PROJECTAP_WORLD_H

#include "Entities/Pacman.h"
#include "Entities/Wall.h"
#include "Entities/Ghost.h"
#include "Entities/Fruit.h"
#include "Entities/Coin.h"
#include "vector"
#include "memory"

using namespace std;

class World {
public:
    World();

    const vector<shared_ptr<Entity>> &getEntities() const;

private:
    int lives = 3;
    vector<shared_ptr<Entity>> entities;
};


#endif //PROJECTAP_WORLD_H
