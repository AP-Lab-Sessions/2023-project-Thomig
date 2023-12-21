#include "Game.h"

void Game::start() {
    renderWindow = make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Pacman");
    stateManager = make_shared<StateManager>(StateManager());
    shared_ptr<StopWatch> stopWatch = StopWatch::getInstance();
    stopWatch->start();
    int stateCooldown = 0;
    string movement1 = "Left";
    string movement2 = "Left";
    string movement3;
    string currentDirection = "Left";
    int updateCount = 0;

    sf::Image spritesImage;
    if (!spritesImage.loadFromFile("../Game Representation/Sprites.png")) {
        // Handle error
        cout << "Error loading sprites" << endl;
    }

    // load font
    shared_ptr<sf::Font> font = make_shared<sf::Font>();
    if (!font->loadFromFile("../Arial.ttf")) {
        // Handle font loading error
        // return EXIT_FAILURE;
    }

    while (renderWindow->isOpen())
    {
        sf::Event event;
        while (renderWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                renderWindow->close();
        }

        stateCooldown++;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
           if(stateManager->getCurrentState()->getType() == "LevelState" and stateCooldown >= 30
           or stateManager->getCurrentState()->getType() == "PausedState" and stateCooldown >= 1000) {
                stateCooldown = 0;
                stateManager->changeState(sf::Keyboard::Escape);
           }
           else if (stateManager->getCurrentState()->getType() == "MenuState") {
                renderWindow->close();
           }
        }
        else if(stateCooldown >= 500 and sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){
            stateCooldown = 0;
            stateManager->changeState(sf::Keyboard::Enter);
        }

        // check if play button in menu is pressed and update state
        else if(stateManager->getCurrentState()->getType() == "MenuState") {
            if(event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if(event.mouseButton.x < 1082 and event.mouseButton.x > 782 and
                    event.mouseButton.y < 826 and event.mouseButton.y > 726){
                        stateManager->changeState(sf::Keyboard::Enter);
                    }
                }
            }
        }

        renderWindow->clear();

        stopWatch->update();

        updateCount++;
        if(stateManager->getCurrentState()->getType() == "LevelState"){
            // update key pressed
            if(updateCount >= 2) {
                updateCount = 0;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) or
                    sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                    movement1 = "Up";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) or
                           sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                    movement1 = "Left";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) or
                           sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                    movement1 = "Down";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) or
                           sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                    movement1 = "Right";
                }
            }
            // pacman movement
            if(movement2 == "Left"){
                if(movement1 == "Left"){
                    stateManager->getCurrentState()->update("Left", false);
                }
                else if(movement1 == "Up"){
                    if(!stateManager->getCurrentState()->update("Up", true)){
                        stateManager->getCurrentState()->update("Left",false);
                    }
                    else{
                        movement2 = "Up";
                    }
                }
                else if(movement1 == "Down"){
                    if(!stateManager->getCurrentState()->update("Down", true)){
                        stateManager->getCurrentState()->update("Left", false);
                    }
                    else{
                        movement2 = "Down";
                    }
                }
                else{
                    stateManager->getCurrentState()->update("Right",false);
                    movement2 = "Right";
                }
            }
            else if(movement2 == "Up"){
                if(movement1 == "Up"){
                    stateManager->getCurrentState()->update("Up",false);
                }
                else if(movement1 == "Left"){
                    if(!stateManager->getCurrentState()->update("Left",true)){
                        stateManager->getCurrentState()->update("Up",false);
                    }
                    else{
                        movement2 = "Left";
                    }
                }
                else if(movement1 == "Right"){
                    if(!stateManager->getCurrentState()->update("Right",true)){
                        stateManager->getCurrentState()->update("Up",false);
                    }
                    else{
                        movement2 = "Right";
                    }
                }
                else{
                    stateManager->getCurrentState()->update("Down",false);
                    movement2 = "Down";
                }
            }
            else if(movement2 == "Right"){
                if(movement1 == "Right"){
                    stateManager->getCurrentState()->update("Right",false);
                }
                else if(movement1 == "Up"){
                    if(!stateManager->getCurrentState()->update("Up",true)){
                        stateManager->getCurrentState()->update("Right",false);
                    }
                    else{
                        movement2 = "Up";
                    }
                }
                else if(movement1 == "Down"){
                    if(!stateManager->getCurrentState()->update("Down",true)){
                        stateManager->getCurrentState()->update("Right",false);
                    }
                    else{
                        movement2 = "Down";
                    }
                }
                else{
                    stateManager->getCurrentState()->update("Left",false);
                    movement2 = "Left";
                }
            }
            else{
                if(movement1 == "Down"){
                    stateManager->getCurrentState()->update("Down",false);
                }
                else if(movement1 == "Left"){
                    if(!stateManager->getCurrentState()->update("Left",true)){
                        stateManager->getCurrentState()->update("Down",false);
                    }
                    else{
                        movement2 = "Left";
                    }
                }
                else if(movement1 == "Right"){
                    if(!stateManager->getCurrentState()->update("Right",true)){
                        stateManager->getCurrentState()->update("Down",false);
                    }
                    else{
                        movement2 = "Right";
                    }
                }
                else{
                    stateManager->getCurrentState()->update("Up",false);
                    movement2 = "Up";
                }
            }
            if(stateManager->getCurrentState()->levelFinished()){
                stateManager->toVictoryState();
            }
            else if(stateManager->getCurrentState()->levelDead()){
                stateManager->toGameOver();
            }
        }

        // draw all shapes
        for (const auto& i : stateManager->getCurrentState()->getShapes()) {
            renderWindow->draw(*i);
        }
        // draw all texts
        for (const auto& i : stateManager->getCurrentState()->getTexts()) {
            renderWindow->draw(i->text);
        }
        // draw all sprites
        for (const auto& i : stateManager->getCurrentState()->getSprites()) {
            renderWindow->draw(i->sprite);
        }

        renderWindow->display();
    }
}
