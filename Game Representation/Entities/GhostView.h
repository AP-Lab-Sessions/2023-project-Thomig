//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_GHOSTVIEW_H
#define PROJECTAP_GHOSTVIEW_H

#include "../EntityView.h"

class GhostView : public EntityView {
public:
    GhostView(std::shared_ptr<GhostModel> ghostModel);

    void update() override;

    void render() override;

private:
    std::shared_ptr<GhostModel> ghostModel;
    vector<shared_ptr<Sprite::Sprite>> ghostSprites;
};


#endif //PROJECTAP_GHOSTVIEW_H
