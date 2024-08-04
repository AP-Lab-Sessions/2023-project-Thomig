//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_WALLVIEW_H
#define PROJECTAP_WALLVIEW_H

#include "../EntityView.h"

class WallModel;

class WallView: public EntityView {
public:
    WallView(std::shared_ptr<WallModel> wallModel) : wallModel(wallModel) {
        // Load Wall shape, set initial position, etc.
    }

    void update() override {
        // Update Wall's position, animation, etc.
        // For example: window->draw(pacManSprite);
    }
private:
    std::shared_ptr<WallModel> wallModel;
};


#endif //PROJECTAP_WALLVIEW_H
