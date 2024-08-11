//
// Created by thomas on 10/08/24.
//

#include "Random.h"

shared_ptr<Random> Random::getInstance() {
    static shared_ptr<Random> instance(new Random);
    return instance;
}

double Random::getRandomNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}