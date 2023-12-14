#include "Game.h"

void Game::start() {
    renderWindow = make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Pacman");
    stateManager = make_shared<StateManager>(StateManager());
    shared_ptr<StopWatch> stopWatch = StopWatch::getInstance();
    stopWatch->start();
    int stateCooldown = 100;
    string movement = "Left";

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

        //cout << stateCooldown << endl;
        stateCooldown += stopWatch->getDeltaTime().count();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) and stateCooldown >= 10){
            stateCooldown = 0;
            if(stateManager->getCurrentState()->getType() == "MenuState"){
                renderWindow->close();
            }
            else {
                stateManager->changeState(sf::Keyboard::Escape);
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) and stateCooldown >= 10){
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

        if(stateManager->getCurrentState()->getType() == "LevelState"){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
                movement = "Up";
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
                movement = "Left";
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
                movement = "Down";
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
                movement = "Right";
            }
            stateManager->getCurrentState()->update(movement);
        }

        // draw all shapes
        for (const auto& i : stateManager->getCurrentState()->getShapes()) {
            renderWindow->draw(*i);
        }
        // draw all texts
        for (const auto& i : stateManager->getCurrentState()->getTexts()) {
            renderWindow->draw(*i);
        }
        // draw all sprites
        for (const auto& i : stateManager->getCurrentState()->getSprites()) {
            sf::Texture texture;
            if(i->getColor() == sf::Color::Cyan){
                sf::IntRect rect(395, 445, 40, 40);
                texture.loadFromImage(spritesImage, rect);
            }
            else if(i->getColor() == sf::Color::Yellow){
                sf::IntRect rect(850, 50, 50, 50);
                texture.loadFromImage(spritesImage, rect);
            }
            else if(i->getColor() == sf::Color::Red){
                sf::IntRect rect(850, 50, 50, 50);
                texture.loadFromImage(spritesImage, rect);
            }
            else if(i->getColor() == sf::Color::Magenta){
                sf::IntRect rect(850, 50, 50, 50);
                texture.loadFromImage(spritesImage, rect);
            }
            i->setTexture(texture);
            renderWindow->draw(*i);
        }
        Camera camera;
        //renderWindow->draw(*camera.test());

        renderWindow->display();
    }
}
