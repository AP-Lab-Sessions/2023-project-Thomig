//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_PACMANVIEW_H
#define PROJECTAP_PACMANVIEW_H

#include "../EntityView.h"

class PacManView : public EntityView {
public:
    PacManView(std::shared_ptr<PacManModel> pacManModel);

    void update() override;

    void render() override;

private:
    std::shared_ptr<PacManModel> pacManModel;
    vector<shared_ptr<Sprite::Sprite>> pacManSprites;
};


#endif //PROJECTAP_PACMANVIEW_H
