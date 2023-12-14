#include "Camera.h"

Camera::Camera() {}

vector<shared_ptr<sf::Shape>> Camera::shapeProjection(const shared_ptr<World>& world) {
    vector<shared_ptr<sf::Shape>> shapes;
    for(auto i: world->getEntities()){
        if(i->getType() == "Wall") {
            shared_ptr<sf::Shape> wall = make_shared<sf::RectangleShape>(sf::Vector2f(50.0f, 50.0f));
            wall->setFillColor(sf::Color::Blue);
            wall->setOrigin(25, 25);
            wall->setPosition(((i->getPosition().first*2)+1)*500+450,
                               ((i->getPosition().second*2)+1)*500-100);
            shapes.push_back(wall);
        }
        //shapes.push_back(shape);
    }
    return shapes;
}

vector<shared_ptr<sf::Sprite>> Camera::spriteProjection(const shared_ptr<World> &world) {
    vector<shared_ptr<sf::Sprite>> sprites;
    for(const auto& i: world->getEntities()) {
        shared_ptr<sf::Sprite> sprite = make_shared<sf::Sprite>();
        if(i->getType() == "Coin") {
            sprite->setColor(sf::Color::Cyan);
        }
        else if(i->getType() == "Pacman") {
            sprite->setColor(sf::Color::Yellow);
        }
        else if(i->getType() == "Fruit") {
            sprite->setColor(sf::Color::Red);
        }
        else if(i->getType() == "Ghost") {
            sprite->setColor(sf::Color::Magenta);
        }
        sprite->setColor(sf::Color::White);
        sprite->setOrigin(25, 25);
        sprite->setPosition(((i->getPosition().first * 2) + 1) * 500 + 450,
                            ((i->getPosition().second * 2) + 1) * 500 - 100);
        sprites.push_back(sprite);
    }
    return sprites;
}

shared_ptr<Sprite> Camera::test() {
    // load sprites
    auto sprite = std::make_shared<Sprite>();
    if (!sprite->image.loadFromFile("../Game Representation/Sprites.png")) {
        // error
        cout << "Error" << endl;
    }

    sprite->texture.loadFromImage(sprite->image, sf::IntRect(850, 50, 50, 50));
    sprite->sprite.setOrigin(25, 25);
    sprite->sprite.setPosition(1000, 500);
    sprite->sprite.setTexture(sprite->texture);

    return sprite;
}
