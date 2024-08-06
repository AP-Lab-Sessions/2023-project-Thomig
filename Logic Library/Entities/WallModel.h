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
    pair<double, double> getPosition() { return position; }
};


#endif //PROJECTAP_WALLMODEL_H
