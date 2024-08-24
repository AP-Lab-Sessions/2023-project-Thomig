//
// Created by thomas on 1/08/24.
//

#include "GhostView.h"

GhostView::GhostView(std::shared_ptr<GhostModel> ghostModel) : ghostModel(ghostModel) {
    // Load Ghost sprite, set initial position, etc.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            auto ghost = make_shared<Sprite::Sprite>();
            ghost->image.loadFromFile("../Game Representation/Sprites.png");
            ghost->texture.loadFromImage(ghost->image, sf::IntRect(i * 50, j * 50, 50, 50));
            ghost->sprite.setTexture(ghost->texture);
            ghost->sprite.setOrigin(20, 25);

            auto &camera = Camera::getInstance();
            pair<double, double> scaleFactor = camera.getScaleFactor();
            ghost->sprite.setScale(scaleFactor.first, scaleFactor.second);
            ghost->sprite.setOrigin((50 * scaleFactor.first) * 0.35, (50 * scaleFactor.second) * 0.4);
            pair<double, double> position = camera.modelEntityPosition(ghostModel->getPosition().first,
                                                                       ghostModel->getPosition().second,
                                                                       50 * scaleFactor.first,
                                                                       50 * scaleFactor.second);
            ghost->sprite.setPosition(position.first, position.second);
            ghostSprites.push_back(ghost);
        }
    }
    for (int i = 0; i < 2; i++) {
        auto ghost = make_shared<Sprite::Sprite>();
        ghost->image.loadFromFile("../Game Representation/Sprites.png");
        ghost->texture.loadFromImage(ghost->image, sf::IntRect(0, 550 + i * 50, 50, 50));
        ghost->sprite.setTexture(ghost->texture);
        ghost->sprite.setOrigin(20, 25);

        auto &camera = Camera::getInstance();
        pair<double, double> scaleFactor = camera.getScaleFactor();
        ghost->sprite.setScale(scaleFactor.first, scaleFactor.second);
        ghost->sprite.setOrigin((50 * scaleFactor.first) * 0.35, (50 * scaleFactor.second) * 0.4);
        pair<double, double> position = camera.modelEntityPosition(ghostModel->getPosition().first,
                                                                   ghostModel->getPosition().second,
                                                                   50 * scaleFactor.first, 50 * scaleFactor.second);
        ghost->sprite.setPosition(position.first, position.second);
        ghostSprites.push_back(ghost);
    }
}

void GhostView::update() {
    // Update Ghost's position, animation, etc.
    auto &camera = Camera::getInstance();
    pair<double, double> position = camera.modelEntityPosition(ghostModel->getPosition().first,
                                                               ghostModel->getPosition().second,
                                                               50 * camera.getScaleFactor().first,
                                                               50 * camera.getScaleFactor().second);
    for (int i = 0; i < ghostSprites.size(); i++) {
        ghostSprites[i]->sprite.setPosition(position.first, position.second);
    }
    render();
}

void GhostView::render() {
    // Get the correct sprite
    int spriteIndex = 0;
    if (ghostModel->getState() != Fear) {
        if (ghostModel->getDirection() == Right) {
            spriteIndex = 0;
        } else if (ghostModel->getDirection() == Down) {
            spriteIndex = 2;
        } else if (ghostModel->getDirection() == Left) {
            spriteIndex = 4;
        } else if (ghostModel->getDirection() == Up) {
            spriteIndex = 6;
        }
    }
    if (ghostModel->getState() == Fear) {
        spriteIndex += 32;
    } else if (ghostModel->getColor() == Pink) {
        spriteIndex += 8;
    } else if (ghostModel->getColor() == Blue) {
        spriteIndex += 16;
    } else if (ghostModel->getColor() == Orange) {
        spriteIndex += 24;
    }
    spriteIndex += ghostModel->getSpriteTimer();
    window->draw(ghostSprites[spriteIndex]->sprite);
}
