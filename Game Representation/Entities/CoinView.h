//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_COINVIEW_H
#define PROJECTAP_COINVIEW_H

#include "../EntityView.h"

class CoinView: public EntityView {
public:
    CoinView(std::shared_ptr<CoinModel> coinModel) : coinModel(coinModel) {
        // Load Coin sprite, set initial position, etc.
    }

    void update() override {
        // Update Coin's position, animation, etc.
        // For example: window->draw(coinSprite);
    }
private:
    std::shared_ptr<CoinModel> coinModel;
};


#endif //PROJECTAP_COINVIEW_H
