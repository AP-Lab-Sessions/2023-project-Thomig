//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_WALLVIEW_H
#define PROJECTAP_WALLVIEW_H

#include "../EntityView.h"

class WallModel;

class WallView: public EntityView {
public:
    WallView(std::shared_ptr<WallModel> wallModel) : wallModel(wallModel) {
        wallShape = make_shared<sf::RectangleShape>(sf::Vector2f(1750.0f, 920.0f));
        wallShape->setFillColor(sf::Color::Black);
        wallShape->setPosition(50, 50);
        wallShape->setOutlineColor(sf::Color::Red);
        wallShape->setOutlineThickness(50);
    }

    void update() override {
        cout << "WallView update" << endl;
        // Update Wall's position, animation, etc.
    }

    //void render() override {
    //    window->draw(*wallShape);
    //}

private:
    std::shared_ptr<WallModel> wallModel;
    shared_ptr<sf::Shape> wallShape;
};


#endif //PROJECTAP_WALLVIEW_H
