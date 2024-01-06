#ifndef PROJECTAP_WORLD_H
#define PROJECTAP_WORLD_H

#include "Entities/Pacman.h"
#include "Entities/Wall.h"
#include "Entities/Ghost.h"
#include "Entities/Fruit.h"
#include "Entities/Coin.h"
#include "StopWatch.h"
#include "Random.h"
#include "Score.h"
#include "LevelStats.h"
#include "vector"
#include "memory"

using namespace std;

class World {
public:
    World();

    bool update(string direction, bool Check);

    const vector<shared_ptr<Entity>> &getEntities() const;

    bool levelFinished();   // true when victory

private:
    // helper functions
    void move(string direction, double multiplier);

    void ghostMove(int ghost, const string& direction, double multiplier);

    void calculateMove(int ghost, const string& currentMoving);

    vector<string> getPossibleMoves(int ghost, const string& currentMoving);

    bool ghostPossibleMove(int ghost, string direction);

    float calculateManhattanDistance(int ghost, string direction);

    static string reverseDirection(const string& direction);

    bool collisionCheck();

    bool ghostCollision(int ghost);

    void updateGhosts();

    vector<shared_ptr<Entity>> entities;
    shared_ptr<Pacman> pacman;
    vector<shared_ptr<Ghost>> ghosts;
    int worldTime = 0;
    float coinPickUpInterval = 1;   // for calculating points from coins
};


#endif //PROJECTAP_WORLD_H
