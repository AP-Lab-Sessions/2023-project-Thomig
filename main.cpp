#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game Representation/Game.h"
#include "Game Representation/Camera.h"
#include "memory"

using namespace std;

int main(){
    // create and start game
    //Game game;
    //game.start();



    sf::RenderWindow window(sf::VideoMode(2048, 1080), "SFML testing");


    // Deze code genereert een pacman sprite om te tekenen op het scherm en werkt

    // load sprites
    sf::Image Sprites;
    if (!Sprites.loadFromFile("../Game Representation/Sprites.png")) {
        // error
        cout << "Error" << endl;
    }

    sf::IntRect rect(850, 50, 50, 50);
    sf::Texture texture;
    texture.loadFromImage(Sprites, rect);

    // Create sf::Sprite using the loaded texture
    shared_ptr<sf::Sprite> pacman1 = make_shared<sf::Sprite>();
    pacman1->setOrigin(25, 25);
    pacman1->setPosition(800, 500);
    pacman1->setTexture(texture);


    // Deze code roept een functie aan Camera::test() met dezelfde code als hierboven om eem pacman sprite te genereren maar
    // deze texture werkt niet en er verschijnt een witte vierkant
    shared_ptr<Sprite> pacman2 = Camera::test();


    // sfml window loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(*pacman1);
        window.draw(pacman2->sprite);
        window.display();
    }

    return 0;
}
