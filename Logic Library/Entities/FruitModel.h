//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_FRUITMODEL_H
#define PROJECTAP_FRUITMODEL_H

#include "../EntityModel.h"

class FruitModel : public EntityModel {
public:
    FruitModel(double x, double y);

    void update() override;

    Rectangle getHitBox() override;
};


#endif //PROJECTAP_FRUITMODEL_H
