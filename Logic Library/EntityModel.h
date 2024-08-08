//
// Created by thomas on 1/08/24.
//

#ifndef PROJECTAP_ENTITYMODEL_H
#define PROJECTAP_ENTITYMODEL_H

#include "utility"
#include "memory"
#include "vector"
#include "Observer.h"

using namespace std;

enum Direction {
    Up,
    Down,
    Left,
    Right
};

enum Type {
    PacMan,
    Ghost,
    Wall,
    Coin,
    Fruit
};

class EntityModel {
public:
    void attachView(shared_ptr<Observer> observer);
    void notify();
    virtual ~EntityModel() = default;
    virtual void update() = 0;
    pair<double, double> getPosition() { return position; }
    Type getType() { return type; }
protected:
    pair<double , double> position;
    Type type;
private:
    vector<shared_ptr<Observer>> observers;
};


#endif //PROJECTAP_ENTITYMODEL_H
