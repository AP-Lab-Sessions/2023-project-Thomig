//
// Created by thomas on 14/08/24.
//

#ifndef PROJECTAP_BANANAVIEW_H
#define PROJECTAP_BANANAVIEW_H

#include "../EntityView.h"

class BananaView : public EntityView {
public:
    BananaView(std::shared_ptr<BananaModel> bananaModel);

    void update() override;

    void render() override;

private:
    std::shared_ptr<BananaModel> bananaModel;
    shared_ptr<Sprite::Sprite> bananaSprite;
};


#endif //PROJECTAP_BANANAVIEW_H
