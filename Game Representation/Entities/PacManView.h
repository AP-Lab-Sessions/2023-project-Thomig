//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_PACMANVIEW_H
#define PROJECTAP_PACMANVIEW_H

#include "../EntityView.h"

class PacManModel;

class PacManView: public EntityView {
public:
    PacManView(std::shared_ptr<PacManModel> pacManModel) : pacManModel(pacManModel) {
        // Load Pac-Man sprite, set initial position, etc.
    }

    void update() override {
        // Update Pac-Man's position, animation, etc.
        // For example: window->draw(pacManSprite);
    }
private:
    std::shared_ptr<PacManModel> pacManModel;
};


#endif //PROJECTAP_PACMANVIEW_H
