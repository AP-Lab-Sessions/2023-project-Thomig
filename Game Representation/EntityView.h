//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_ENTITYVIEW_H
#define PROJECTAP_ENTITYVIEW_H

#include "SFML/Graphics.hpp"
#include "../Logic Library/Observer.h"
#include "iostream"

using namespace std;

class EntityView: public Observer {
public:
    virtual void update() = 0;
    virtual ~EntityView() = default;
protected:
    shared_ptr<sf::RenderWindow> window;
};


#endif //PROJECTAP_ENTITYVIEW_H
