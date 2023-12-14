#include "Random.h"

shared_ptr<Random> Random::getInstance() {
    return shared_ptr<Random>(new Random());
}

double Random::getRandomNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}
