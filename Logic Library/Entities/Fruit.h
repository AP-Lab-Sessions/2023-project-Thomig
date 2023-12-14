//
// Created by thomas on 11/12/23.
//

#ifndef PROJECTAP_FRUIT_H
#define PROJECTAP_FRUIT_H

#include "../Entity.h"

class Fruit: public Entity{
public:
    string getType() override;
};


#endif //PROJECTAP_FRUIT_H
