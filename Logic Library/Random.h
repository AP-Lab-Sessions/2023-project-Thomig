#ifndef PROJECTAP_RANDOM_H
#define PROJECTAP_RANDOM_H

#include "random"
#include "memory"

using namespace std;

// singleton class
class Random {
private:
    Random(){};
public:
    static shared_ptr<Random> getInstance();

    static double getRandomNumber();
};


#endif //PROJECTAP_RANDOM_H
