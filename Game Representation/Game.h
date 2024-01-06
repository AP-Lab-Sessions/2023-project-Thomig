#ifndef PROJECTAP_GAME_H
#define PROJECTAP_GAME_H

#include "StateManager.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include "iostream"
#include "../Logic Library/StopWatch.h"
#include "../Logic Library/LevelStats.h"
#include "Camera.h"

using namespace std;

class Game {
public:
    void start();

private:
    unique_ptr<sf::RenderWindow> renderWindow;
    shared_ptr<StateManager> stateManager;
};


#endif //PROJECTAP_GAME_H
