#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game Representation/Game.h"
#include "Game Representation/Camera.h"
#include "memory"
#include "Logic Library/LevelStats.h"
#include "fstream"
#include "sstream"

using namespace std;

int main(){
    // create and start game
    Game game;
    game.start();

    return 0;
}