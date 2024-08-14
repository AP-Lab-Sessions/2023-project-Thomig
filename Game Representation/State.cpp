//
// Created by thomas on 31/07/24.
//

#include "State.h"

State::State(std::shared_ptr<StateManager> manager) : stateManager(manager) {
    // Load font
    font = std::make_shared<sf::Font>();
    try {
        // check if file is found
        if (!font->loadFromFile("../Arial.ttf")) {
            throw runtime_error("File Arial.ttf is not found or unable to open");
        }
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
}
