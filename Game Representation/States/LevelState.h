//
// Created by thomas on 4/12/23.
//

#ifndef PROJECTAP_LEVELSTATE_H
#define PROJECTAP_LEVELSTATE_H

#include "../State.h"

class LevelState: public State {
public:
    string getType() override;

    [[nodiscard]] const vector<shared_ptr<sf::Shape>> &getShapes() const override;

    [[nodiscard]] const vector<shared_ptr<sf::Text>> &getTexts() const override;

    [[nodiscard]] const vector<shared_ptr<sf::Sprite>> &getSprites() const override;

    LevelState();

    void update(const string& direction) override;


private:
    vector<shared_ptr<sf::Shape>> shapes;
    vector<shared_ptr<sf::Text>> texts;
    vector<shared_ptr<sf::Sprite>> sprites;
    shared_ptr<World> world;
    shared_ptr<Camera> camera;
};


#endif //PROJECTAP_LEVELSTATE_H
