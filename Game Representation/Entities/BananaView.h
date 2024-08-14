//
// Created by thomas on 14/08/24.
//

#ifndef PROJECTAP_BANANAVIEW_H
#define PROJECTAP_BANANAVIEW_H

#include "../EntityView.h"

class BananaView: public EntityView {
public:
    BananaView(std::shared_ptr<BananaModel> bananaModel) : bananaModel(bananaModel) {
            // Load Banana sprite, set initial position, etc.
            auto banana = make_shared<Sprite>();
            if (!banana->image.loadFromFile("../Game Representation/Sprites.png")) {
                // error
                cout << "Error" << endl;
            }
            banana->texture.loadFromImage(banana->image, sf::IntRect(600, 250, 50, 50));
            banana->sprite.setTexture(banana->texture);

            auto& camera = Camera::getInstance();
            pair<double, double> scaleFactor = camera.getScaleFactor();
            banana->sprite.setScale(scaleFactor.first, scaleFactor.second);
            banana->sprite.setOrigin((50*scaleFactor.first)*0.45, (50*scaleFactor.second)*0.5);
            pair<double, double> position = camera.modelPosition(bananaModel->getPosition().first,
            bananaModel->getPosition().second, 50*scaleFactor.first, 50*scaleFactor.second);
            banana->sprite.setPosition(position.first, position.second);
            bananaSprite = banana;
    }

    void update() override {
        render();
    }

    void render() override {
        // Render Banana
        window->draw(bananaSprite->sprite);
    }
private:
    std::shared_ptr<BananaModel> bananaModel;
    shared_ptr<Sprite> bananaSprite;
};


#endif //PROJECTAP_BANANAVIEW_H
