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
    void setPosition(double x, double y) { position = make_pair(x, y); }
    Direction getDirection() { return direction; }
    void setDirection(Direction d) { direction = d; }
private:
    Direction direction;
};


#endif //PROJECTAP_PACMANMODEL_H
