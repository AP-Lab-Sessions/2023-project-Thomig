#ifndef PROJECTAP_CAMERA_H
#define PROJECTAP_CAMERA_H

#include "../Logic Library/World.h"
#include "vector"
#include "memory"
#include <SFML/Graphics.hpp>
#include "iostream"

using namespace std;

struct Sprite {
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Image image;
};

class Camera {
public:
    Camera();

    static vector<shared_ptr<sf::Shape>> shapeProjection(const shared_ptr<World>& world);

    static vector<shared_ptr<sf::Sprite>> spriteProjection(const shared_ptr<World>& world);

    static shared_ptr<Sprite> test();
};


#endif //PROJECTAP_CAMERA_H
