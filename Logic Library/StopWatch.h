//
// Created by thomas on 8/08/24.
//

#ifndef PROJECTAP_STOPWATCH_H
#define PROJECTAP_STOPWATCH_H

#include "memory"
#include "chrono"

using namespace std;

// singleton class to keep the time
class StopWatch {
public:
    static shared_ptr<StopWatch> getInstance();

    void start();

    void update();

    void reset();

    [[nodiscard]] const chrono::microseconds &getDeltaTime() const; // gives time past since last frame

private:
    StopWatch() {};

    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    chrono::microseconds deltaTime;
};


#endif //PROJECTAP_STOPWATCH_H
