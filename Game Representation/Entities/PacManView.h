//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_PACMANVIEW_H
#define PROJECTAP_PACMANVIEW_H

#include "../EntityView.h"

class PacManView: public EntityView {
public:
    PacManView(std::shared_ptr<PacManModel> pacManModel) : pacManModel(pacManModel) {
        // Load Pac-Man sprites, set initial position, etc.
        vector<int> pacmanRect = {500, 350, 200, 50, 550, 400, 250, 100, 500, 350, 200, 50, 450, 300, 150, 0};
        for (auto i: pacmanRect) {
            auto pacman = make_shared<Sprite>();
            pacman->image.loadFromFile("../Game Representation/Sprites.png");
            pacman->texture.loadFromImage(pacman->image, sf::IntRect(850, i, 50, 50));
            pacman->sprite.setTexture(pacman->texture);

            auto& camera = Camera::getInstance();
            pair<double, double> scaleFactor = camera.getScaleFactor();
            pacman->sprite.setScale(scaleFactor.first, scaleFactor.second);
            pacman->sprite.setOrigin((50*scaleFactor.first)*0.35, (50*scaleFactor.second)*0.4);
            pair<double, double> position = camera.modelPosition(pacManModel->getPosition().first,
                pacManModel->getPosition().second, 50*scaleFactor.first, 50*scaleFactor.second);
            pacman->sprite.setPosition(position.first, position.second);
            pacManSprites.push_back(pacman);
        }
    }

    void update() override {
        // Update Position
        auto& camera = Camera::getInstance();
        pair<double, double> position = camera.modelPosition(pacManModel->getPosition().first,
                                                             pacManModel->getPosition().second,
                                                             50*camera.getScaleFactor().first,
                                                             50*camera.getScaleFactor().second);
        for (int i = 0; i < pacManSprites.size(); i++) {
            pacManSprites[i]->sprite.setPosition(position.first, position.second);
        }
        render();
    }

    void render() override {
        // Render correct sprite
        int spriteIndex = 0;
        if (pacManModel->getDirection() == Up) {
            spriteIndex = 0;
        } else if (pacManModel->getDirection() == Left) {
            spriteIndex = 1;
        } else if (pacManModel->getDirection() == Down) {
            spriteIndex = 2;
        } else if (pacManModel->getDirection() == Right) {
            spriteIndex = 3;
        }
        spriteIndex += pacManModel->getSpriteTimer()*4;
        window->draw(pacManSprites[spriteIndex]->sprite); // up left down right 0 1 2 3
    }
private:
    std::shared_ptr<PacManModel> pacManModel;
    vector<shared_ptr<Sprite>> pacManSprites;
};


#endif //PROJECTAP_PACMANVIEW_H
