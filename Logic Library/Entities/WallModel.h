//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_WALLMODEL_H
#define PROJECTAP_WALLMODEL_H

#include "../EntityModel.h"

class WallModel: public EntityModel {
public:
    WallModel(double x, double y);
    void update() override;
    Rectangle getHitBox() override;
};


#endif //PROJECTAP_WALLMODEL_H
