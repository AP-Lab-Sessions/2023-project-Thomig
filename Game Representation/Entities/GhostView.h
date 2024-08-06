//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_GHOSTVIEW_H
#define PROJECTAP_GHOSTVIEW_H

#include "../EntityView.h"

class GhostView: public EntityView {
public:
    GhostView(std::shared_ptr<GhostModel> ghostModel) : ghostModel(ghostModel) {
        // Load Ghost sprite, set initial position, etc.
    }

    void update() override {
        // Update Ghost's position, animation, etc.
        // For example: window->draw(ghostSprite);
    }
private:
    std::shared_ptr<GhostModel> ghostModel;
};


#endif //PROJECTAP_GHOSTVIEW_H
