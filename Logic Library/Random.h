#ifndef PROJECTAP_RANDOM_H
#define PROJECTAP_RANDOM_H

#include "random"
#include "memory"

using namespace std;

// singleton class
class Random {
public:
    static shared_ptr<Random> getInstance();

    // get random number between 0 and 1
    static double getRandomNumber();

private:
    Random(){};
};


#endif //PROJECTAP_RANDOM_H
