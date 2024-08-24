//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_COINMODEL_H
#define PROJECTAP_COINMODEL_H

#include "../EntityModel.h"

class CoinModel : public EntityModel {
public:
    CoinModel(double x, double y);

    void update() override;

    Rectangle getHitBox() override;
};


#endif //PROJECTAP_COINMODEL_H
