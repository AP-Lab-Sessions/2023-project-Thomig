//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_WALLVIEW_H
#define PROJECTAP_WALLVIEW_H

#include "../EntityView.h"

class WallView : public EntityView {
public:
    WallView(std::shared_ptr<WallModel> wallModel);

    void update() override;

    void render() override;

private:
    std::shared_ptr<WallModel> wallModel;
    shared_ptr<sf::Shape> wallShape;
};


#endif //PROJECTAP_WALLVIEW_H
