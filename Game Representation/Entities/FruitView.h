//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_FRUITVIEW_H
#define PROJECTAP_FRUITVIEW_H

#include "../EntityView.h"

class FruitView : public EntityView {
public:
    FruitView(std::shared_ptr<FruitModel> fruitModel);

    void update() override;

    void render() override;

private:
    std::shared_ptr<FruitModel> fruitModel;
    shared_ptr<Sprite::Sprite> fruitSprite;
};


#endif //PROJECTAP_FRUITVIEW_H
