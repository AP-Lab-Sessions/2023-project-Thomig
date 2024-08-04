//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_PACMANMODEL_H
#define PROJECTAP_PACMANMODEL_H

#include "../EntityModel.h"

class PacManModel: public EntityModel {
public:
    PacManModel(double x, double y);
    void update() override;
};


#endif //PROJECTAP_PACMANMODEL_H
