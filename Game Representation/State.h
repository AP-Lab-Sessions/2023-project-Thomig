//
// Created by thomas on 4/12/23.
//

#ifndef PROJECTAP_STATE_H
#define PROJECTAP_STATE_H

#include "string"
#include "memory"
#include "../Logic Library/Score.h"
#include "../Logic Library/World.h"
#include "Camera.h"
#include "../Logic Library/StopWatch.h"
#include <SFML/Graphics.hpp>

using namespace std;

class State {
public:
    virtual string getType() = 0;

    virtual void update(const string& direction) = 0;

    [[nodiscard]] virtual const vector<shared_ptr<sf::Shape>> &getShapes() const = 0;

    [[nodiscard]] virtual const vector<shared_ptr<sf::Text>> &getTexts() const = 0;

    [[nodiscard]] virtual const vector<shared_ptr<sf::Sprite>> &getSprites() const = 0;

};


#endif //PROJECTAP_STATE_H
