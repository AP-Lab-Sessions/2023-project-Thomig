//
// Created by thomas on 4/12/23.
//

#ifndef PROJECTAP_VICTORYSTATE_H
#define PROJECTAP_VICTORYSTATE_H

#include "../State.h"

class VictoryState: public State {
public:
    string getType() override;

    [[nodiscard]] const vector<shared_ptr<sf::Shape>> &getShapes() const override;

    [[nodiscard]] const vector<shared_ptr<sf::Text>> &getTexts() const override;

    [[nodiscard]] const vector<shared_ptr<sf::Sprite>> &getSprites() const override;

    VictoryState();

    void update(const string& direction) override;

private:
    vector<shared_ptr<sf::Shape>> shapes;
    vector<shared_ptr<sf::Text>> texts;
    vector<shared_ptr<sf::Sprite>> sprites;
};


#endif //PROJECTAP_VICTORYSTATE_H
