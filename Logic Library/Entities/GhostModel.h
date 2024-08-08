//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_GHOSTMODEL_H
#define PROJECTAP_GHOSTMODEL_H

#include "../EntityModel.h"

class GhostModel: public EntityModel {
public:
    GhostModel(double x, double y);
    void update() override;
    void setPosition(double x, double y) { position = make_pair(x, y); }
    Direction getDirection() { return direction; }
private:
    Direction direction = Left;
};


#endif //PROJECTAP_GHOSTMODEL_H
