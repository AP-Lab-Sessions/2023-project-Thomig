//
// Created by thomas on 1/12/23.
//

#include "World.h"

World::World() {
    // setup the walls
    vector<pair<double,double>> wallPositions;

    // outer rectangle
    wallPositions.emplace_back(-0.50,-0.25);
    wallPositions.emplace_back(-0.45,-0.25);
    wallPositions.emplace_back(-0.40,-0.25);
    wallPositions.emplace_back(-0.35,-0.25);
    wallPositions.emplace_back(-0.30,-0.25);
    wallPositions.emplace_back(-0.25,-0.25);
    wallPositions.emplace_back(-0.20,-0.25);
    wallPositions.emplace_back(-0.15,-0.25);
    wallPositions.emplace_back(-0.10,-0.25);
    wallPositions.emplace_back(-0.05,-0.25);
    wallPositions.emplace_back(0.00,-0.25);
    wallPositions.emplace_back(0.05,-0.25);
    wallPositions.emplace_back(0.10,-0.25);
    wallPositions.emplace_back(0.15,-0.25);
    wallPositions.emplace_back(0.20,-0.25);
    wallPositions.emplace_back(0.25,-0.25);
    wallPositions.emplace_back(0.30,-0.25);
    wallPositions.emplace_back(0.35,-0.25);
    wallPositions.emplace_back(0.40,-0.25);
    wallPositions.emplace_back(0.45,-0.25);

    wallPositions.emplace_back(-0.50,-0.20);
    wallPositions.emplace_back(-0.50,-0.15);
    wallPositions.emplace_back(-0.50,-0.10);
    wallPositions.emplace_back(-0.50,-0.05);
    wallPositions.emplace_back(-0.50,0.00);
    wallPositions.emplace_back(-0.50,0.05);
    wallPositions.emplace_back(-0.50,0.10);
    wallPositions.emplace_back(-0.50,0.15);
    wallPositions.emplace_back(-0.50,0.20);
    wallPositions.emplace_back(-0.50,0.25);

    wallPositions.emplace_back(-0.45,0.25);
    wallPositions.emplace_back(-0.40,0.25);
    wallPositions.emplace_back(-0.35,0.25);
    wallPositions.emplace_back(-0.30,0.25);
    wallPositions.emplace_back(-0.25,0.25);
    wallPositions.emplace_back(-0.20,0.25);
    wallPositions.emplace_back(-0.15,0.25);
    wallPositions.emplace_back(-0.10,0.25);
    wallPositions.emplace_back(-0.05,0.25);
    wallPositions.emplace_back(0.00,0.25);
    wallPositions.emplace_back(0.05,0.25);
    wallPositions.emplace_back(0.10,0.25);
    wallPositions.emplace_back(0.15,0.25);
    wallPositions.emplace_back(0.20,0.25);
    wallPositions.emplace_back(0.25,0.25);
    wallPositions.emplace_back(0.30,0.25);
    wallPositions.emplace_back(0.35,0.25);
    wallPositions.emplace_back(0.40,0.25);
    wallPositions.emplace_back(0.45,0.25);

    wallPositions.emplace_back(0.45,-0.20);
    wallPositions.emplace_back(0.45,-0.15);
    wallPositions.emplace_back(0.45,-0.10);
    wallPositions.emplace_back(0.45,-0.05);
    wallPositions.emplace_back(0.45,0.00);
    wallPositions.emplace_back(0.45,0.05);
    wallPositions.emplace_back(0.45,0.10);
    wallPositions.emplace_back(0.45,0.15);
    wallPositions.emplace_back(0.45,0.20);

    // 4 pieces connected to outer rectangle
    wallPositions.emplace_back(-0.25,-0.20);
    wallPositions.emplace_back(-0.25,-0.15);

    wallPositions.emplace_back(0.20,-0.20);
    wallPositions.emplace_back(0.20,-0.15);

    wallPositions.emplace_back(-0.25,0.20);
    wallPositions.emplace_back(-0.25,0.15);

    wallPositions.emplace_back(0.20,0.20);
    wallPositions.emplace_back(0.20,0.15);

    // 4 L shapes
    wallPositions.emplace_back(-0.40,-0.15);
    wallPositions.emplace_back(-0.35,-0.15);
    wallPositions.emplace_back(-0.40,-0.10);
    wallPositions.emplace_back(-0.40,-0.05);

    wallPositions.emplace_back(-0.40,0.05);
    wallPositions.emplace_back(-0.35,0.15);
    wallPositions.emplace_back(-0.40,0.10);
    wallPositions.emplace_back(-0.40,0.15);

    wallPositions.emplace_back(0.35,-0.15);
    wallPositions.emplace_back(0.30,-0.15);
    wallPositions.emplace_back(0.35,-0.10);
    wallPositions.emplace_back(0.35,-0.05);

    wallPositions.emplace_back(0.35,0.05);
    wallPositions.emplace_back(0.30,0.15);
    wallPositions.emplace_back(0.35,0.10);
    wallPositions.emplace_back(0.35,0.15);

    // 4 small platforms
    wallPositions.emplace_back(-0.30,-0.05);
    wallPositions.emplace_back(-0.25,-0.05);

    wallPositions.emplace_back(-0.30,0.05);
    wallPositions.emplace_back(-0.25,0.05);

    wallPositions.emplace_back(0.20,-0.05);
    wallPositions.emplace_back(0.25,-0.05);

    wallPositions.emplace_back(0.20,0.05);
    wallPositions.emplace_back(0.25,0.05);

    // 2 big platforms
    wallPositions.emplace_back(-0.15,-0.15);
    wallPositions.emplace_back(-0.10,-0.15);
    wallPositions.emplace_back(-0.05,-0.15);
    wallPositions.emplace_back(0.00,-0.15);
    wallPositions.emplace_back(0.05,-0.15);
    wallPositions.emplace_back(0.10,-0.15);

    wallPositions.emplace_back(-0.15,0.15);
    wallPositions.emplace_back(-0.10,0.15);
    wallPositions.emplace_back(-0.05,0.15);
    wallPositions.emplace_back(0.00,0.15);
    wallPositions.emplace_back(0.05,0.15);
    wallPositions.emplace_back(0.10,0.15);

    // middle platform
    wallPositions.emplace_back(-0.15,0.05);
    wallPositions.emplace_back(-0.10,0.05);
    wallPositions.emplace_back(-0.05,0.05);
    wallPositions.emplace_back(0.00,0.05);
    wallPositions.emplace_back(0.05,0.05);
    wallPositions.emplace_back(0.10,0.05);
    wallPositions.emplace_back(-0.15,0.00);
    wallPositions.emplace_back(-0.15,-0.05);
    wallPositions.emplace_back(-0.10,-0.05);
    wallPositions.emplace_back(0.10,0.00);
    wallPositions.emplace_back(0.10,-0.05);
    wallPositions.emplace_back(0.05,-0.05);

    for(auto i: wallPositions) {
        shared_ptr<Wall> wall = make_unique<Wall>(Wall(i));
        entities.push_back(wall);
    }

    vector<pair<double,double>> coinPositions;
    coinPositions.emplace_back(-0.40,-0.20);

    for(auto i: coinPositions) {
        shared_ptr<Coin> coin = make_unique<Coin>(Coin(i));
        entities.push_back(coin);
    }

    shared_ptr<Pacman> pacman = make_unique<Pacman>(Pacman(make_pair(0.00,0.20)));
    entities.push_back(pacman);
}

const vector<shared_ptr<Entity>> &World::getEntities() const {
    return entities;
}
