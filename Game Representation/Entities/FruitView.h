//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_FRUITVIEW_H
#define PROJECTAP_FRUITVIEW_H

#include "../EntityView.h"

class FruitView: public EntityView {
public:
    FruitView(std::shared_ptr<FruitModel> fruitModel) : fruitModel(fruitModel) {
        // Load Fruit sprite, set initial position, etc.
        auto fruit = make_shared<Sprite>();
        if (!fruit->image.loadFromFile("../Game Representation/Sprites.png")) {
            // error
            cout << "Error" << endl;
        }
        fruit->texture.loadFromImage(fruit->image, sf::IntRect(543, 548, 50, 50));
        fruit->sprite.setTexture(fruit->texture);

        auto& camera = Camera::getInstance();
        pair<double, double> scaleFactor = camera.getScaleFactor();
        fruit->sprite.setScale(scaleFactor.first*0.7, scaleFactor.second*0.7);
        fruit->sprite.setOrigin((50*scaleFactor.first)*0.55, (50*scaleFactor.second)*0.45);
        pair<double, double> position = camera.modelPosition(fruitModel->getPosition().first,
                                                             fruitModel->getPosition().second, 50*scaleFactor.first, 50*scaleFactor.second);
        fruit->sprite.setPosition(position.first, position.second);
        fruitSprite = fruit;
    }

    void update() override {
        // Update Fruit's position, animation, etc.
        render();
    }

    void render() override {
        // Render Fruit
        window->draw(fruitSprite->sprite);
    }
private:
    std::shared_ptr<FruitModel> fruitModel;
    shared_ptr<Sprite> fruitSprite;
};


#endif //PROJECTAP_FRUITVIEW_H
