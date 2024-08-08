//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_GHOSTVIEW_H
#define PROJECTAP_GHOSTVIEW_H

#include "../EntityView.h"

class GhostView: public EntityView {
public:
    GhostView(std::shared_ptr<GhostModel> ghostModel) : ghostModel(ghostModel) {
        // Load Ghost sprite, set initial position, etc.
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                auto ghost = make_shared<Sprite>();
                ghost->image.loadFromFile("../Game Representation/Sprites.png");
                ghost->texture.loadFromImage(ghost->image, sf::IntRect(i * 50, j * 50, 50, 50));
                ghost->sprite.setTexture(ghost->texture);
                ghost->sprite.setOrigin(20, 25);

                auto& camera = Camera::getInstance();
                pair<double, double> scaleFactor = camera.getScaleFactor();
                ghost->sprite.setScale(scaleFactor.first, scaleFactor.second);
                ghost->sprite.setOrigin((50*scaleFactor.first)*0.35, (50*scaleFactor.second)*0.4);
                pair<double, double> position = camera.modelPosition(ghostModel->getPosition().first,
                                                                     ghostModel->getPosition().second, 50*scaleFactor.first, 50*scaleFactor.second);
                ghost->sprite.setPosition(position.first, position.second);
                ghostSprites.push_back(ghost);
            }
        }
        for (int i = 0; i < 2; i++) {
            auto ghost = make_shared<Sprite>();
            ghost->image.loadFromFile("../Game Representation/Sprites.png");
            ghost->texture.loadFromImage(ghost->image, sf::IntRect(0, 550 + i * 50, 50, 50));
            ghost->sprite.setTexture(ghost->texture);
            ghost->sprite.setOrigin(20, 25);

            auto& camera = Camera::getInstance();
            pair<double, double> scaleFactor = camera.getScaleFactor();
            ghost->sprite.setScale(scaleFactor.first, scaleFactor.second);
            ghost->sprite.setOrigin((50*scaleFactor.first)*0.35, (50*scaleFactor.second)*0.4);
            pair<double, double> position = camera.modelPosition(ghostModel->getPosition().first,
                                                                 ghostModel->getPosition().second, 50*scaleFactor.first, 50*scaleFactor.second);
            ghost->sprite.setPosition(position.first, position.second);
            ghostSprites.push_back(ghost);
        }
    }

    void update() override {
        // Update Ghost's position, animation, etc.
        render();
    }

    void render() override {
        // Render Ghost
        window->draw(ghostSprites[0]->sprite);
    }
private:
    std::shared_ptr<GhostModel> ghostModel;
    vector<shared_ptr<Sprite>> ghostSprites;
};


#endif //PROJECTAP_GHOSTVIEW_H
