//
// Created by thomas on 4/08/24.
//

#ifndef PROJECTAP_OBSERVER_H
#define PROJECTAP_OBSERVER_H

#include "memory"
#include "vector"

using namespace std;

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};


#endif //PROJECTAP_OBSERVER_H
