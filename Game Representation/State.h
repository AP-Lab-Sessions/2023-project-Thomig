//
// Created by thomas on 4/12/23.
//

#ifndef PROJECTAP_STATE_H
#define PROJECTAP_STATE_H

#include "string"
#include "memory"
#include "../Logic Library/Score.h"
#include "../Logic Library/World.h"
#include "../Logic Library/StopWatch.h"
#include "../Logic Library/LevelStats.h"
#include "Camera.h"
#include <SFML/Graphics.hpp>

using namespace std;

class State {
public:
    virtual string getType() = 0;

    virtual bool update(const string &direction, bool check);

    virtual void update();

    [[nodiscard]] const vector<shared_ptr<sf::Shape>> &getShapes() const;

    [[nodiscard]] const vector<shared_ptr<Text>> &getTexts() const;

    [[nodiscard]] const vector<shared_ptr<Sprite>> &getSprites() const;

    virtual bool levelFinished();

    // everything to draw on window
    vector<shared_ptr<sf::Shape>> shapes;
    vector<shared_ptr<Text>> texts;
    vector<shared_ptr<Sprite>> sprites;
};


#endif //PROJECTAP_STATE_H
