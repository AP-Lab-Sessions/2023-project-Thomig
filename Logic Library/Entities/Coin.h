//
// Created by thomas on 11/12/23.
//

#ifndef PROJECTAP_COIN_H
#define PROJECTAP_COIN_H

#include "../Entity.h"

class Coin: public Entity{
public:
    string getType() override;

    explicit Coin(const pair<float, float> &position);

    vector<float> getHitbox();

};


#endif //PROJECTAP_COIN_H
