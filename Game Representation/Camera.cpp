//
// Created by thomas on 1/08/24.
//

#include "Camera.h"

Camera &Camera::getInstance() {
    static Camera instance;
    return instance;
}

pair<double, double> Camera::modelPosition(double x, double y, double entityWidth, double entityHeight) {
    return {width*0.20 + (((x+1)*0.5)*20)*entityWidth, height*0.20
    + (((y+1)*0.5)*20)*entityHeight};

}

pair<double, double> Camera::entitySize(double x, double y) {
    return {ceil(width/32), ceil(height/18)};
}

pair<double, double> Camera::getScaleFactor() {
    return {(width/32.0)/50.0, (height/18.0)/50.0};
}
