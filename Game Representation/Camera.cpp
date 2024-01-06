#include "Camera.h"

Camera::Camera() {
    // load coin sprite
    auto coin1 = make_shared<Sprite>();
    if(!coin1->image.loadFromFile("../Game Representation/Sprites.png")){
        // error
        cout << "Error" << endl;
    }
    coin1->texture.loadFromImage(coin1->image, sf::IntRect(505,605,22,25));
    coin1->sprite.setOrigin(11,16);
    coin1->sprite.setTexture(coin1->texture);
    coin = coin1;

    // load fruit sprite
    auto fruit1 = make_shared<Sprite>();
    fruit1->image.loadFromFile("../Game Representation/Sprites.png");
    fruit1->texture.loadFromImage(fruit1->image, sf::IntRect(543,548,50,50));
    fruit1->sprite.setOrigin(25,25);
    fruit1->sprite.setTexture(fruit1->texture);
    fruit1->sprite.scale(0.7,0.7);
    fruit = fruit1;

    // load all pacman sprites
    // up 1
    auto pacman1 = make_shared<Sprite>();
    pacman1->image.loadFromFile("../Game Representation/Sprites.png");
    pacman1->texture.loadFromImage(pacman1->image, sf::IntRect(850,500,50,50));
    pacman1->sprite.setOrigin(22,25);
    pacman1->sprite.setTexture(pacman1->texture);
    pacman.push_back(pacman1);

    // left 1
    auto pacman2 = make_shared<Sprite>();
    pacman2->image.loadFromFile("../Game Representation/Sprites.png");
    pacman2->texture.loadFromImage(pacman2->image, sf::IntRect(850,350,50,50));
    pacman2->sprite.setOrigin(22,25);
    pacman2->sprite.setTexture(pacman2->texture);
    pacman.push_back(pacman2);

    // down 1
    auto pacman3 = make_shared<Sprite>();
    pacman3->image.loadFromFile("../Game Representation/Sprites.png");
    pacman3->texture.loadFromImage(pacman3->image, sf::IntRect(850,200,50,50));
    pacman3->sprite.setOrigin(22,25);
    pacman3->sprite.setTexture(pacman3->texture);
    pacman.push_back(pacman3);

    // right 1
    auto pacman4 = make_shared<Sprite>();
    pacman4->image.loadFromFile("../Game Representation/Sprites.png");
    pacman4->texture.loadFromImage(pacman4->image, sf::IntRect(850,50,50,50));
    pacman4->sprite.setOrigin(22,25);
    pacman4->sprite.setTexture(pacman4->texture);
    pacman.push_back(pacman4);

    // up 2
    auto pacman5 = make_shared<Sprite>();
    pacman5->image.loadFromFile("../Game Representation/Sprites.png");
    pacman5->texture.loadFromImage(pacman5->image, sf::IntRect(850,550,50,50));
    pacman5->sprite.setOrigin(22,25);
    pacman5->sprite.setTexture(pacman5->texture);
    pacman.push_back(pacman5);

    // left 2
    auto pacman6 = make_shared<Sprite>();
    pacman6->image.loadFromFile("../Game Representation/Sprites.png");
    pacman6->texture.loadFromImage(pacman6->image, sf::IntRect(850,400,50,50));
    pacman6->sprite.setOrigin(22,25);
    pacman6->sprite.setTexture(pacman6->texture);
    pacman.push_back(pacman6);

    // down 2
    auto pacman7 = make_shared<Sprite>();
    pacman7->image.loadFromFile("../Game Representation/Sprites.png");
    pacman7->texture.loadFromImage(pacman7->image, sf::IntRect(850,250,50,50));
    pacman7->sprite.setOrigin(22,25);
    pacman7->sprite.setTexture(pacman7->texture);
    pacman.push_back(pacman7);

    // right 2
    auto pacman8 = make_shared<Sprite>();
    pacman8->image.loadFromFile("../Game Representation/Sprites.png");
    pacman8->texture.loadFromImage(pacman8->image, sf::IntRect(850,100,50,50));
    pacman8->sprite.setOrigin(22,25);
    pacman8->sprite.setTexture(pacman8->texture);
    pacman.push_back(pacman8);

    // up 3
    auto pacman9 = make_shared<Sprite>();
    pacman9->image.loadFromFile("../Game Representation/Sprites.png");
    pacman9->texture.loadFromImage(pacman9->image, sf::IntRect(850,500,50,50));
    pacman9->sprite.setOrigin(22,25);
    pacman9->sprite.setTexture(pacman9->texture);
    pacman.push_back(pacman9);

    // left 3
    auto pacman10 = make_shared<Sprite>();
    pacman10->image.loadFromFile("../Game Representation/Sprites.png");
    pacman10->texture.loadFromImage(pacman10->image, sf::IntRect(850,350,50,50));
    pacman10->sprite.setOrigin(22,25);
    pacman10->sprite.setTexture(pacman10->texture);
    pacman.push_back(pacman10);

    // down 3
    auto pacman11 = make_shared<Sprite>();
    pacman11->image.loadFromFile("../Game Representation/Sprites.png");
    pacman11->texture.loadFromImage(pacman11->image, sf::IntRect(850,200,50,50));
    pacman11->sprite.setOrigin(22,25);
    pacman11->sprite.setTexture(pacman11->texture);
    pacman.push_back(pacman11);

    // right 3
    auto pacman12 = make_shared<Sprite>();
    pacman12->image.loadFromFile("../Game Representation/Sprites.png");
    pacman12->texture.loadFromImage(pacman12->image, sf::IntRect(850,50,50,50));
    pacman12->sprite.setOrigin(22,25);
    pacman12->sprite.setTexture(pacman12->texture);
    pacman.push_back(pacman12);

    // up 4
    auto pacman13 = make_shared<Sprite>();
    pacman13->image.loadFromFile("../Game Representation/Sprites.png");
    pacman13->texture.loadFromImage(pacman13->image, sf::IntRect(850,450,50,50));
    pacman13->sprite.setOrigin(22,25);
    pacman13->sprite.setTexture(pacman13->texture);
    pacman.push_back(pacman13);

    // left 4
    auto pacman14 = make_shared<Sprite>();
    pacman14->image.loadFromFile("../Game Representation/Sprites.png");
    pacman14->texture.loadFromImage(pacman14->image, sf::IntRect(850,300,50,50));
    pacman14->sprite.setOrigin(22,25);
    pacman14->sprite.setTexture(pacman14->texture);
    pacman.push_back(pacman14);

    // down 4
    auto pacman15 = make_shared<Sprite>();
    pacman15->image.loadFromFile("../Game Representation/Sprites.png");
    pacman15->texture.loadFromImage(pacman15->image, sf::IntRect(850,150,50,50));
    pacman15->sprite.setOrigin(22,25);
    pacman15->sprite.setTexture(pacman15->texture);
    pacman.push_back(pacman15);

    // right 4
    auto pacman16 = make_shared<Sprite>();
    pacman16->image.loadFromFile("../Game Representation/Sprites.png");
    pacman16->texture.loadFromImage(pacman8->image, sf::IntRect(850,0,50,50));
    pacman16->sprite.setOrigin(22,25);
    pacman16->sprite.setTexture(pacman16->texture);
    pacman.push_back(pacman16);

    // load all ghost sprites
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            auto ghost1 = make_shared<Sprite>();
            ghost1->image.loadFromFile("../Game Representation/Sprites.png");
            ghost1->texture.loadFromImage(ghost1->image, sf::IntRect(i*50,j*50,50,50));
            ghost1->sprite.setOrigin(20,25);
            ghost1->sprite.setTexture(ghost1->texture);
            ghost.push_back(ghost1);
        }
    }
    for(int i = 0; i < 2; i++) {
        auto ghost1 = make_shared<Sprite>();
        ghost1->image.loadFromFile("../Game Representation/Sprites.png");
        ghost1->texture.loadFromImage(ghost1->image, sf::IntRect(0, 550+i*50,50, 50));
        ghost1->sprite.setOrigin(20, 25);
        ghost1->sprite.setTexture(ghost1->texture);
        ghost.push_back(ghost1);
    }
}

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
    }
    return shapes;
}

vector<shared_ptr<Text>> Camera::textProjection(const shared_ptr<World> &world) {
    shared_ptr<LevelStats> levelStats = LevelStats::getInstance();
    vector<shared_ptr<Text>> texts;

    // set font
    shared_ptr<Text> text1 = make_shared<Text>();
    if (!text1->font.loadFromFile("../Arial.ttf")) {
        // Handle font loading error
        // return EXIT_FAILURE;
        cout << "Error" << endl;
    }

    text1->text.setFont(text1->font);
    string s = "Score: ";
    s += to_string(levelStats->getScore());
    text1->text.setString(s);
    text1->text.setCharacterSize(50);
    text1->text.setFillColor(sf::Color::Yellow);
    text1->text.setPosition(430,690);
    texts.push_back(text1);

    shared_ptr<Text> text2 = make_shared<Text>();
    if (!text2->font.loadFromFile("../Arial.ttf")) {
        // Handle font loading error
        // return EXIT_FAILURE;
        cout << "Error" << endl;
    }

    text2->text.setFont(text2->font);
    s = "Lives: " + to_string(levelStats->getLives());
    text2->text.setString(s);
    text2->text.setCharacterSize(50);
    text2->text.setFillColor(sf::Color::Yellow);
    text2->text.setPosition(1250,690);
    texts.push_back(text2);

    return texts;
}

vector<shared_ptr<Sprite>> Camera::spriteProjection(const shared_ptr<World> &world) {
    vector<shared_ptr<Sprite>> sprites;
    for(const auto& i: world->getEntities()) {
        auto sprite = make_shared<Sprite>();
        if(i->getType() == "Coin") {
            sprite->sprite = coin->sprite;
            sprite->texture = coin->texture;
            sprite->image = coin->image;
        }
        else if(i->getType() == "Pacman") {
            if(i->moving == "Up") {
                sprite->sprite = pacman[4*(i->state/10)]->sprite;
                sprite->texture = pacman[4*(i->state/10)]->texture;
                sprite->image = pacman[4*(i->state/10)]->image;
            }
            else if(i->moving == "Left") {
                sprite->sprite = pacman[1+4*(i->state/10)]->sprite;
                sprite->texture = pacman[1+4*(i->state/10)]->texture;
                sprite->image = pacman[1+4*(i->state/10)]->image;
            }
            else if(i->moving == "Down") {
                sprite->sprite = pacman[2+4*(i->state/10)]->sprite;
                sprite->texture = pacman[2+4*(i->state/10)]->texture;
                sprite->image = pacman[2+4*(i->state/10)]->image;
            }
            else if(i->moving == "Right") {
                sprite->sprite = pacman[3+4*(i->state/10)]->sprite;
                sprite->texture = pacman[3+4*(i->state/10)]->texture;
                sprite->image = pacman[3+4*(i->state/10)]->image;
            }
        }
        else if(i->getType() == "Fruit") {
            sprite->sprite = fruit->sprite;
            sprite->texture = fruit->texture;
            sprite->image = fruit->image;

        }
        else if(i->getType() == "Ghost") {
            int s = 0;
            if(i->state/20 == 1){
                s = 1;
            }
            if(i->fear != 0){
                sprite->sprite = ghost[32+s]->sprite;
                sprite->texture = ghost[32+s]->texture;
            }
            else {
                int m = 0;
                if(i->moving == "Down"){
                    m = 2;
                }
                else if(i->moving == "Left"){
                    m = 4;
                }
                else if(i->moving == "Up"){
                    m = 6;
                }
                int sm = s+m;
                if (i->getColor() == "Red") {
                    sprite->sprite = ghost[sm]->sprite;
                    sprite->texture = ghost[sm]->texture;
                } else if (i->getColor() == "Pink") {
                    sprite->sprite = ghost[sm+8]->sprite;
                    sprite->texture = ghost[sm+8]->texture;
                } else if (i->getColor() == "Blue") {
                    sprite->sprite = ghost[sm+16]->sprite;
                    sprite->texture = ghost[sm+16]->texture;
                } else if (i->getColor() == "Orange") {
                    sprite->sprite = ghost[sm+24]->sprite;
                    sprite->texture = ghost[sm+24]->texture;
                }
            }
            sprite->image = ghost[0]->image;

        }
        sprite->sprite.setPosition(((i->getPosition().first * 2) + 1) * 500 + 450,
                                   ((i->getPosition().second * 2) + 1) * 500 - 100);
        sprites.push_back(sprite);
    }
    return sprites;
}

shared_ptr<Sprite> Camera::test() {
    /*
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
    shared_ptr<sf::Sprite> pacman = make_shared<sf::Sprite>();
    pacman->setOrigin(25, 25);
    pacman->setPosition(1000, 500);
    pacman->setTexture(texture);

    return pacman;
     */
    auto sprite = make_shared<Sprite>();
    if(!sprite->image.loadFromFile("../Game Representation/Sprites.png")){
        // error
        cout << "Error" << endl;
    }

    sprite->texture.loadFromImage(sprite->image, sf::IntRect(850,50,50,50));
    sprite->sprite.setOrigin(25,25);
    sprite->sprite.setTexture(sprite->texture);

    return sprite;
}
