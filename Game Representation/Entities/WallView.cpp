//
// Created by thomas on 1/08/24.
//

#include "WallView.h"

WallView::WallView(std::shared_ptr<WallModel> wallModel) : wallModel(wallModel) {
    auto &camera = Camera::getInstance();
    pair<double, double> size = camera.entitySize(50, 50);
    pair<double, double> position = camera.modelEntityPosition(wallModel->getPosition().first,
                                                               wallModel->getPosition().second, size.first,
                                                               size.second);
    wallShape = make_shared<sf::RectangleShape>(sf::Vector2f(size.first, size.second));
    wallShape->setOrigin(size.first / 2, size.second / 2);
    wallShape->setPosition(position.first, position.second);
    wallShape->setFillColor(sf::Color::Blue);
}

void WallView::update() {
    render();
}

void WallView::render() {
    window->draw(*wallShape);
}
