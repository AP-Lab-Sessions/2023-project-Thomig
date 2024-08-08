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
        auto coin = make_shared<Sprite>();
        if (!coin->image.loadFromFile("../Game Representation/Sprites.png")) {
            // error
            cout << "Error" << endl;
        }
        coin->texture.loadFromImage(coin->image, sf::IntRect(505, 605, 22, 25));
        coin->sprite.setTexture(coin->texture);

        auto& camera = Camera::getInstance();
        pair<double, double> scaleFactor = camera.getScaleFactor();
        coin->sprite.setScale(scaleFactor.first, scaleFactor.second);
        coin->sprite.setOrigin((50*scaleFactor.first)*0.25, (50*scaleFactor.second)*0.3);
        pair<double, double> position = camera.modelPosition(coinModel->getPosition().first,
                                                             coinModel->getPosition().second, 50*scaleFactor.first, 50*scaleFactor.second);
        coin->sprite.setPosition(position.first, position.second);
        coinSprite = coin;
    }

    void update() override {
        // Update Coin's position, animation, etc.
        render();
    }

    void render() override {
        // Render Coin
        window->draw(coinSprite->sprite);
    }
private:
    std::shared_ptr<CoinModel> coinModel;
    shared_ptr<Sprite> coinSprite;
};


#endif //PROJECTAP_COINVIEW_H
