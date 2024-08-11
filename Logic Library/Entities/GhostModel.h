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
    Direction getDirection();
    void setDirection(Direction d);
    Rectangle getHitBox() override;
    void incrementSpriteTimer();
    int getSpriteTimer() { return spriteTimer; }
    Color getColor() { return color; }
    void setColor(Color c) { color = c; }
    ghostState getState() { return state; }
    void setState(ghostState s) { state = s; }
    void resetChangeDirectionTimer() { changeDirectionTimer = 0; }
    void updateChangeDirectionTimer() { changeDirectionTimer++; }
    bool changeDirection();

private:
    Direction direction = Left;
    int spriteTimer = 0;
    Color color;
    ghostState state = Setup;
    int changeDirectionTimer = 0;
};


#endif //PROJECTAP_GHOSTMODEL_H
