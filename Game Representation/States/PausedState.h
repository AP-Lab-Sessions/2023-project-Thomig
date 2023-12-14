//
// Created by thomas on 4/12/23.
//

#ifndef PROJECTAP_PAUSEDSTATE_H
#define PROJECTAP_PAUSEDSTATE_H

#include "../State.h"

class PausedState: public State {
public:
    string getType() override;

    [[nodiscard]] const vector<shared_ptr<sf::Shape>> &getShapes() const override;

    [[nodiscard]] const vector<shared_ptr<sf::Text>> &getTexts() const override;

    [[nodiscard]] const vector<shared_ptr<sf::Sprite>> &getSprites() const override;

    PausedState();

    void update(const string& direction) override;

private:
    vector<shared_ptr<sf::Shape>> shapes;
    vector<shared_ptr<sf::Text>> texts;
    vector<shared_ptr<sf::Sprite>> sprites;
};


#endif //PROJECTAP_PAUSEDSTATE_H
