//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_ENTITYVIEW_H
#define PROJECTAP_ENTITYVIEW_H

#include "SFML/Graphics.hpp"
#include "../Logic Library/Observer.h"
#include "iostream"
#include "RenderWindow.h"
#include "../Logic Library/Entities/PacManModel.h"
#include "../Logic Library/Entities/GhostModel.h"
#include "../Logic Library/Entities/WallModel.h"
#include "../Logic Library/Entities/CoinModel.h"
#include "../Logic Library/Entities/FruitModel.h"

using namespace std;

class EntityView: public Observer {
public:
    virtual void update() = 0;
    virtual ~EntityView() = default;
    //virtual void render() = 0;
protected:
    std::shared_ptr<sf::RenderWindow> window = RenderWindow::getInstance().getWindow();
};


#endif //PROJECTAP_ENTITYVIEW_H
