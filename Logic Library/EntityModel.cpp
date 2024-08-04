//
// Created by thomas on 1/08/24.
//

#include "EntityModel.h"

void EntityModel::attachView(shared_ptr <Observer> observer) {
    observers.push_back(observer);
}

void EntityModel::notify() {
    for (auto observer : observers) {
        observer->update();
    }
}
