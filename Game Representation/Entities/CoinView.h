//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_COINVIEW_H
#define PROJECTAP_COINVIEW_H

#include "../EntityView.h"

class CoinView : public EntityView {
public:
    CoinView(std::shared_ptr<CoinModel> coinModel);

    void update() override;

    void render() override;

private:
    std::shared_ptr<CoinModel> coinModel;
    shared_ptr<Sprite::Sprite> coinSprite;
};


#endif //PROJECTAP_COINVIEW_H
