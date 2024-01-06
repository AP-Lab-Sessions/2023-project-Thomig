#ifndef PROJECTAP_CAMERA_H
#define PROJECTAP_CAMERA_H

#include "../Logic Library/World.h"
#include "../Logic Library/LevelStats.h"
#include "vector"
#include "memory"
#include <SFML/Graphics.hpp>
#include "iostream"

using namespace std;

// structs for keeping data
struct Text {
    sf::Text text;
    sf::Font font;
};

struct Sprite {
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Image image;
};

class Camera {
public:
    Camera();

    static vector<shared_ptr<sf::Shape>> shapeProjection(const shared_ptr<World>& world);

    static vector<shared_ptr<Text>> textProjection(const shared_ptr<World>& world);

    vector<shared_ptr<Sprite>> spriteProjection(const shared_ptr<World>& world);

private:
    // all sprites textures
    shared_ptr<Sprite> coin;
    shared_ptr<Sprite> fruit;
    vector<shared_ptr<Sprite>> pacman;
    vector<shared_ptr<Sprite>> ghost;
};


#endif //PROJECTAP_CAMERA_H
