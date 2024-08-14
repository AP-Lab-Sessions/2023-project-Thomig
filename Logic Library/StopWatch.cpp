//
// Created by thomas on 8/08/24.
//

#include "StopWatch.h"

shared_ptr<StopWatch> StopWatch::getInstance() {
    static shared_ptr<StopWatch> instance(new StopWatch);
    return instance;
}

void StopWatch::start() {
    startTime = chrono::high_resolution_clock::now();
}

void StopWatch::update() {
    auto currentTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::microseconds>(currentTime - startTime);
    startTime = currentTime;
    deltaTime = elapsedTime;
}

void StopWatch::reset() {
    startTime = chrono::high_resolution_clock::now();
    deltaTime = chrono::microseconds(0);
}

const chrono::microseconds &StopWatch::getDeltaTime() const {
    return deltaTime;
}
