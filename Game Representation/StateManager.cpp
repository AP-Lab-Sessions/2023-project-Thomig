#include "StateManager.h"

string StateManager::getCurrentStateType() {
    if(stateStack.empty()){
        return "None";
    }
    return stateStack.top()->getType();
}

shared_ptr<State> StateManager::getCurrentState() {
    return stateStack.top();
}

StateManager::StateManager() {
    stack<shared_ptr<State>> stack;
    shared_ptr<MenuState> menuState = make_shared<MenuState>(MenuState());
    stack.push(menuState);
    stateStack = stack;
}

void StateManager::changeState(sf::Keyboard::Key key) {
    if(key == sf::Keyboard::Key::Escape){
        if(getCurrentStateType() == "LevelState"){
            shared_ptr<PausedState> pausedState = make_shared<PausedState>(PausedState());
            stateStack.push(pausedState);
        }
        else{
            stateStack.pop();
        }
    }
    else if(key == sf::Keyboard::Key::Enter){
        if(getCurrentStateType() == "GameOverState"){
            stateStack.pop();
            shared_ptr<LevelState> levelState = make_shared<LevelState>(LevelState());
            stateStack.push(levelState);
        }
        else if(getCurrentStateType() == "MenuState"){
            shared_ptr<LevelState> levelState = make_shared<LevelState>(LevelState());
            stateStack.push(levelState);
        }
        else if(getCurrentStateType() == "PausedState"){
            stateStack.pop();
        }
        else if(getCurrentStateType() == "VictoryState"){
            stateStack.pop();
            shared_ptr<LevelState> levelState = make_shared<LevelState>(LevelState());
            stateStack.push(levelState);
        }
    }
}

void StateManager::toGameOver() {
    stateStack.pop();
    shared_ptr<GameOverState> gameOverState = make_shared<GameOverState>(GameOverState());
    stateStack.push(gameOverState);
}

void StateManager::toVictoryState() {
    stateStack.pop();
    shared_ptr<VictoryState> victoryState = make_shared<VictoryState>(VictoryState());
    stateStack.push(victoryState);
}
