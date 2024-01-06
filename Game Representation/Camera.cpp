#include "Camera.h"

Camera::Camera() {  // load all sprites
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
    vector<int> pacmanRectTop = {500,350,200,50,550,400,250,100,500,350,200,50,450,300,150,0};
    for(auto i: pacmanRectTop){
        auto pacman1 = make_shared<Sprite>();
        pacman1->image.loadFromFile("../Game Representation/Sprites.png");
        pacman1->texture.loadFromImage(pacman1->image, sf::IntRect(850,i,50,50));
        pacman1->sprite.setOrigin(22,25);
        pacman1->sprite.setTexture(pacman1->texture);
        pacman.push_back(pacman1);
    }

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
    try {
        // check if file is found
        if (!text1->font.loadFromFile("../Arial.ttf")) {
            throw runtime_error("File Arial.ttf is not found or unable to open");
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
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

    text2->text.setFont(text1->font);
    s = "Lives: " + to_string(levelStats->getLives());
    text2->text.setString(s);
    text2->text.setCharacterSize(50);
    text2->text.setFillColor(sf::Color::Yellow);
    text2->text.setPosition(1250,690);
    texts.push_back(text2);

    return texts;
}

vector<shared_ptr<Sprite>> Camera::spriteProjection(const shared_ptr<World> &world) {
    // display all entities using the correct sprite
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
