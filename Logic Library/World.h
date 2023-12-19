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
#include "vector"
#include "memory"

using namespace std;

class World {
public:
    World();

    bool update(string direction, bool Check);

    const vector<shared_ptr<Entity>> &getEntities() const;

    int getLives() const;

    const double getScore() const;

    void move(string direction, double multiplier);

    void ghostMove(int ghost, string direction, double multiplier);

    string calculateMove(int ghost, string currentMoving);

    bool ghostPossibleMove(int ghost, string direction);

    float calculateManhattanDistance(int ghost, string direction);

    bool collisionCheck();

    bool ghostCollision(int ghost);

    bool check(string direction);

    bool getFear() const;

    void setLives(int lives);

    void setScore(const shared_ptr<Score> &score);

    bool levelFinished();

private:
    void updateGhosts();

    int lives = 3;
    shared_ptr<Score> score;
    vector<shared_ptr<Entity>> entities;
    shared_ptr<Pacman> pacman;
    vector<shared_ptr<Ghost>> ghosts;
    string lastDirection;
    int fear;
    int worldTime = 0;
};


#endif //PROJECTAP_WORLD_H
