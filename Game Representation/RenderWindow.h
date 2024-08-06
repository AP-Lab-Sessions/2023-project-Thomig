//
// Created by thomas on 6/08/24.
//

#ifndef PROJECTAP_RENDERWINDOW_H
#define PROJECTAP_RENDERWINDOW_H

#include <SFML/Graphics.hpp>
#include <memory>

// singleton class to keep an instance of the render window
class RenderWindow {
public:
    static RenderWindow& getInstance() {
        static RenderWindow instance;
        return instance;
    }

    void initialize(unsigned int width, unsigned int height, const std::string& title) {
        window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);
    }

    std::shared_ptr<sf::RenderWindow> getWindow() {
        return window;
    }

private:
    RenderWindow() = default;
    ~RenderWindow() = default;
    RenderWindow(const RenderWindow&) = delete;
    RenderWindow& operator=(const RenderWindow&) = delete;

    std::shared_ptr<sf::RenderWindow> window;
};


#endif //PROJECTAP_RENDERWINDOW_H
