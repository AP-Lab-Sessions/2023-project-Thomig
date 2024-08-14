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
    void setPosition(double x, double y);
    Direction getDirection();
    void setDirection(Direction d);
    Rectangle getHitBox() override;
    void incrementSpriteTimer();
    int getSpriteTimer() { return spriteTimer; }
    void resetPosition();
private:
    Direction direction = Right;
    int spriteTimer = 0;
    pair<double, double> startingPosition;
};


#endif //PROJECTAP_PACMANMODEL_H
