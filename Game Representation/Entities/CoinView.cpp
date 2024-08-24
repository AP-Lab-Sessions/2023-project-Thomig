//
// Created by thomas on 1/08/24.
//

#include "CoinView.h"

CoinView::CoinView(std::shared_ptr<CoinModel> coinModel) : coinModel(coinModel) {
    // Load Coin sprite, set initial position, etc.
    auto coin = make_shared<Sprite::Sprite>();
    if (!coin->image.loadFromFile("../Game Representation/Sprites.png")) {
        // error
        cout << "Error" << endl;
    }
    coin->texture.loadFromImage(coin->image, sf::IntRect(505, 605, 22, 25));
    coin->sprite.setTexture(coin->texture);

    auto &camera = Camera::getInstance();
    pair<double, double> scaleFactor = camera.getScaleFactor();
    coin->sprite.setScale(scaleFactor.first, scaleFactor.second);
    coin->sprite.setOrigin((50 * scaleFactor.first) * 0.25, (50 * scaleFactor.second) * 0.3);
    pair<double, double> position = camera.modelEntityPosition(coinModel->getPosition().first,
                                                               coinModel->getPosition().second,
                                                               50 * scaleFactor.first, 50 * scaleFactor.second);
    coin->sprite.setPosition(position.first, position.second);
    coinSprite = coin;
}

void CoinView::update() {
    // Update Coin's position, animation, etc.
    render();
}

void CoinView::render() {
    // Render Coin
    window->draw(coinSprite->sprite);
}
