//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_FRUITVIEW_H
#define PROJECTAP_FRUITVIEW_H

#include "../EntityView.h"

class FruitModel;

class FruitView: public EntityView {
public:
    FruitView(std::shared_ptr<FruitModel> fruitModel) : fruitModel(fruitModel) {
        // Load Fruit sprite, set initial position, etc.
    }

    void update() override {
        // Update Fruit's position, animation, etc.
        // For example: window->draw(fruitSprite);
    }
private:
    std::shared_ptr<FruitModel> fruitModel;
};


#endif //PROJECTAP_FRUITVIEW_H
