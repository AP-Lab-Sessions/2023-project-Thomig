//
// Created by thomas on 4/12/23.
//

#ifndef PROJECTAP_LEVELSTATE_H
#define PROJECTAP_LEVELSTATE_H

#include "../State.h"

class LevelState: public State {
public:
    string getType() override;

    LevelState(int lives, int score);

    bool update(const string& direction, bool check) override;

    bool levelFinished() override;

private:
    shared_ptr<World> world;
    shared_ptr<Camera> camera;
};


#endif //PROJECTAP_LEVELSTATE_H
