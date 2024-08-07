//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_CAMERA_H
#define PROJECTAP_CAMERA_H

#include "SFML/Graphics.hpp"
#include "RenderWindow.h"
#include "utility"
#include "cmath"

using namespace std;

// Singleton class to model positions of entities and calculate their size
class Camera {
public:
    static Camera& getInstance();

    pair<double, double> modelPosition(double x, double y, double entityWidth, double entityHeight);

    pair<double, double> entitySize(double x, double y);

    pair<double, double> getScaleFactor();

private:
    Camera() = default;
    ~Camera() = default;
    Camera(const Camera&) = delete;
    Camera& operator=(const Camera&) = delete;

    int width = RenderWindow::getInstance().getWindow()->getSize().x;
    int height = RenderWindow::getInstance().getWindow()->getSize().y;
};


#endif //PROJECTAP_CAMERA_H
