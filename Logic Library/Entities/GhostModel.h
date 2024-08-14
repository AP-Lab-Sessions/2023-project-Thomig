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
    void setPosition(double x, double y);
    Direction getDirection();
    void setDirection(Direction d);
    Rectangle getHitBox() override;
    Rectangle getHitBox1();
    void incrementSpriteTimer();
    int getSpriteTimer();
    Color getColor() { return color; }
    void setColor(Color c) { color = c; }
    ghostState getState();
    void setState(ghostState s) { state = s; }
    void resetChangeDirectionTimer() { changeDirectionTimer = 0; }
    void updateChangeDirectionTimer() { changeDirectionTimer++; }
    bool changeDirection();
    void enableFear();
    void resetPosition();
    void savePosition();
    void restorePosition();

private:
    Direction direction = Up;
    int spriteTimer = 0;
    Color color;
    ghostState state = Setup;
    int changeDirectionTimer = 0;
    pair<double, double> startingPosition;
    pair<double, double> savedPosition;
    int fearTimer = 0;
};


#endif //PROJECTAP_GHOSTMODEL_H
