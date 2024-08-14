//
// Created by thomas on 14/08/24.
//

#ifndef PROJECTAP_BANANAMODEL_H
#define PROJECTAP_BANANAMODEL_H

#include "../EntityModel.h"

class BananaModel: public EntityModel {
public:
    BananaModel(double x, double y);
    void update() override;
    Rectangle getHitBox() override;
};


#endif //PROJECTAP_BANANAMODEL_H
