#ifndef PROJECTAP_STOPWATCH_H
#define PROJECTAP_STOPWATCH_H

#include "memory"
#include "chrono"

using namespace std;

// singleton class
class StopWatch {
public:
    static shared_ptr<StopWatch> getInstance();

    void start();

    void update();

    [[nodiscard]] const chrono::milliseconds &getDeltaTime() const;

    int k;

private:
    StopWatch(){};

    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    chrono::milliseconds deltaTime;
};


#endif //PROJECTAP_STOPWATCH_H
