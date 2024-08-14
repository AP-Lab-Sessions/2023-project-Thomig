//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_WALLVIEW_H
#define PROJECTAP_WALLVIEW_H

#include "../EntityView.h"

class WallView: public EntityView {
public:
    WallView(std::shared_ptr<WallModel> wallModel) : wallModel(wallModel) {
        auto& camera = Camera::getInstance();
        pair<double, double> size = camera.entitySize(50, 50);
        pair<double, double> position = camera.modelPosition(wallModel->getPosition().first, wallModel->getPosition().second
                , size.first, size.second);
        wallShape = make_shared<sf::RectangleShape>(sf::Vector2f(size.first, size.second));
        wallShape->setOrigin(size.first/2, size.second/2);
        wallShape->setPosition(position.first, position.second);
        wallShape->setFillColor(sf::Color::Blue);
    }

    void update() override {
        render();
    }

    void render() override {
        window->draw(*wallShape);
    }

private:
    std::shared_ptr<WallModel> wallModel;
    shared_ptr<sf::Shape> wallShape;
};


#endif //PROJECTAP_WALLVIEW_H
