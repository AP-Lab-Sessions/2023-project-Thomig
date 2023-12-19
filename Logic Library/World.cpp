//
// Created by thomas on 1/12/23.
//

#include "World.h"

World::World() {
    // setup the walls
    vector<pair<double,double>> wallPositions;

    // outer rectangle
    wallPositions.emplace_back(-0.50,-0.25);
    wallPositions.emplace_back(-0.45,-0.25);
    wallPositions.emplace_back(-0.40,-0.25);
    wallPositions.emplace_back(-0.35,-0.25);
    wallPositions.emplace_back(-0.30,-0.25);
    wallPositions.emplace_back(-0.25,-0.25);
    wallPositions.emplace_back(-0.20,-0.25);
    wallPositions.emplace_back(-0.15,-0.25);
    wallPositions.emplace_back(-0.10,-0.25);
    wallPositions.emplace_back(-0.05,-0.25);
    wallPositions.emplace_back(0.00,-0.25);
    wallPositions.emplace_back(0.05,-0.25);
    wallPositions.emplace_back(0.10,-0.25);
    wallPositions.emplace_back(0.15,-0.25);
    wallPositions.emplace_back(0.20,-0.25);
    wallPositions.emplace_back(0.25,-0.25);
    wallPositions.emplace_back(0.30,-0.25);
    wallPositions.emplace_back(0.35,-0.25);
    wallPositions.emplace_back(0.40,-0.25);
    wallPositions.emplace_back(0.45,-0.25);

    wallPositions.emplace_back(-0.50,-0.20);
    wallPositions.emplace_back(-0.50,-0.15);
    wallPositions.emplace_back(-0.50,-0.10);
    wallPositions.emplace_back(-0.50,-0.05);
    wallPositions.emplace_back(-0.50,0.00);
    wallPositions.emplace_back(-0.50,0.05);
    wallPositions.emplace_back(-0.50,0.10);
    wallPositions.emplace_back(-0.50,0.15);
    wallPositions.emplace_back(-0.50,0.20);
    wallPositions.emplace_back(-0.50,0.25);

    wallPositions.emplace_back(-0.45,0.25);
    wallPositions.emplace_back(-0.40,0.25);
    wallPositions.emplace_back(-0.35,0.25);
    wallPositions.emplace_back(-0.30,0.25);
    wallPositions.emplace_back(-0.25,0.25);
    wallPositions.emplace_back(-0.20,0.25);
    wallPositions.emplace_back(-0.15,0.25);
    wallPositions.emplace_back(-0.10,0.25);
    wallPositions.emplace_back(-0.05,0.25);
    wallPositions.emplace_back(0.00,0.25);
    wallPositions.emplace_back(0.05,0.25);
    wallPositions.emplace_back(0.10,0.25);
    wallPositions.emplace_back(0.15,0.25);
    wallPositions.emplace_back(0.20,0.25);
    wallPositions.emplace_back(0.25,0.25);
    wallPositions.emplace_back(0.30,0.25);
    wallPositions.emplace_back(0.35,0.25);
    wallPositions.emplace_back(0.40,0.25);
    wallPositions.emplace_back(0.45,0.25);

    wallPositions.emplace_back(0.45,-0.20);
    wallPositions.emplace_back(0.45,-0.15);
    wallPositions.emplace_back(0.45,-0.10);
    wallPositions.emplace_back(0.45,-0.05);
    wallPositions.emplace_back(0.45,0.00);
    wallPositions.emplace_back(0.45,0.05);
    wallPositions.emplace_back(0.45,0.10);
    wallPositions.emplace_back(0.45,0.15);
    wallPositions.emplace_back(0.45,0.20);

    // 4 pieces connected to outer rectangle
    wallPositions.emplace_back(-0.25,-0.20);
    wallPositions.emplace_back(-0.25,-0.15);

    wallPositions.emplace_back(0.20,-0.20);
    wallPositions.emplace_back(0.20,-0.15);

    wallPositions.emplace_back(-0.25,0.20);
    wallPositions.emplace_back(-0.25,0.15);

    wallPositions.emplace_back(0.20,0.20);
    wallPositions.emplace_back(0.20,0.15);

    // 4 L shapes
    wallPositions.emplace_back(-0.40,-0.15);
    wallPositions.emplace_back(-0.35,-0.15);
    wallPositions.emplace_back(-0.40,-0.10);
    wallPositions.emplace_back(-0.40,-0.05);

    wallPositions.emplace_back(-0.40,0.05);
    wallPositions.emplace_back(-0.35,0.15);
    wallPositions.emplace_back(-0.40,0.10);
    wallPositions.emplace_back(-0.40,0.15);

    wallPositions.emplace_back(0.35,-0.15);
    wallPositions.emplace_back(0.30,-0.15);
    wallPositions.emplace_back(0.35,-0.10);
    wallPositions.emplace_back(0.35,-0.05);

    wallPositions.emplace_back(0.35,0.05);
    wallPositions.emplace_back(0.30,0.15);
    wallPositions.emplace_back(0.35,0.10);
    wallPositions.emplace_back(0.35,0.15);

    // 4 small platforms
    wallPositions.emplace_back(-0.30,-0.05);
    wallPositions.emplace_back(-0.25,-0.05);

    wallPositions.emplace_back(-0.30,0.05);
    wallPositions.emplace_back(-0.25,0.05);

    wallPositions.emplace_back(0.20,-0.05);
    wallPositions.emplace_back(0.25,-0.05);

    wallPositions.emplace_back(0.20,0.05);
    wallPositions.emplace_back(0.25,0.05);

    // 2 big platforms
    wallPositions.emplace_back(-0.15,-0.15);
    wallPositions.emplace_back(-0.10,-0.15);
    wallPositions.emplace_back(-0.05,-0.15);
    wallPositions.emplace_back(0.00,-0.15);
    wallPositions.emplace_back(0.05,-0.15);
    wallPositions.emplace_back(0.10,-0.15);

    wallPositions.emplace_back(-0.15,0.15);
    wallPositions.emplace_back(-0.10,0.15);
    wallPositions.emplace_back(-0.05,0.15);
    wallPositions.emplace_back(0.00,0.15);
    wallPositions.emplace_back(0.05,0.15);
    wallPositions.emplace_back(0.10,0.15);

    // middle platform
    wallPositions.emplace_back(-0.15,0.05);
    wallPositions.emplace_back(-0.10,0.05);
    wallPositions.emplace_back(-0.05,0.05);
    wallPositions.emplace_back(0.00,0.05);
    wallPositions.emplace_back(0.05,0.05);
    wallPositions.emplace_back(0.10,0.05);
    wallPositions.emplace_back(-0.15,0.00);
    wallPositions.emplace_back(-0.15,-0.05);
    wallPositions.emplace_back(-0.10,-0.05);
    wallPositions.emplace_back(0.10,0.00);
    wallPositions.emplace_back(0.10,-0.05);
    wallPositions.emplace_back(0.05,-0.05);

    for(auto i: wallPositions) {
        shared_ptr<Wall> wall = make_unique<Wall>(Wall(i));
        entities.push_back(wall);
    }

    vector<pair<double,double>> coinPositions;

    // coins per layer placement
    coinPositions.emplace_back(-0.40,-0.20);
    coinPositions.emplace_back(-0.35,-0.20);
    coinPositions.emplace_back(-0.30,-0.20);
    coinPositions.emplace_back(-0.20,-0.20);
    coinPositions.emplace_back(-0.15,-0.20);
    coinPositions.emplace_back(-0.10,-0.20);
    coinPositions.emplace_back(-0.05,-0.20);
    coinPositions.emplace_back(-0.00,-0.20);
    coinPositions.emplace_back(0.05,-0.20);
    coinPositions.emplace_back(0.10,-0.20);
    coinPositions.emplace_back(0.15,-0.20);
    coinPositions.emplace_back(0.25,-0.20);
    coinPositions.emplace_back(0.30,-0.20);
    coinPositions.emplace_back(0.35,-0.20);
    coinPositions.emplace_back(0.40,-0.20);

    coinPositions.emplace_back(-0.45,-0.15);
    coinPositions.emplace_back(-0.30,-0.15);
    coinPositions.emplace_back(-0.20,-0.15);
    coinPositions.emplace_back(0.15,-0.15);
    coinPositions.emplace_back(0.25,-0.15);
    coinPositions.emplace_back(0.40,-0.15);

    coinPositions.emplace_back(-0.45,-0.10);
    coinPositions.emplace_back(-0.35,-0.10);
    coinPositions.emplace_back(-0.30,-0.10);
    coinPositions.emplace_back(-0.25,-0.10);
    coinPositions.emplace_back(-0.20,-0.10);
    coinPositions.emplace_back(-0.15,-0.10);
    coinPositions.emplace_back(-0.10,-0.10);
    coinPositions.emplace_back(-0.05,-0.10);
    coinPositions.emplace_back(-0.00,-0.10);
    coinPositions.emplace_back(0.05,-0.10);
    coinPositions.emplace_back(0.10,-0.10);
    coinPositions.emplace_back(0.15,-0.10);
    coinPositions.emplace_back(0.20,-0.10);
    coinPositions.emplace_back(0.25,-0.10);
    coinPositions.emplace_back(0.30,-0.10);
    coinPositions.emplace_back(0.40,-0.10);

    coinPositions.emplace_back(-0.45,-0.05);
    coinPositions.emplace_back(-0.35,-0.05);
    coinPositions.emplace_back(-0.20,-0.05);
    coinPositions.emplace_back(0.15,-0.05);
    coinPositions.emplace_back(0.30,-0.05);
    coinPositions.emplace_back(0.40,-0.05);

    coinPositions.emplace_back(-0.45,0.00);
    coinPositions.emplace_back(-0.40,0.00);
    coinPositions.emplace_back(-0.35,0.00);
    coinPositions.emplace_back(-0.30,0.00);
    coinPositions.emplace_back(-0.25,0.00);
    coinPositions.emplace_back(-0.20,0.00);
    coinPositions.emplace_back(0.15,0.00);
    coinPositions.emplace_back(0.20,0.00);
    coinPositions.emplace_back(0.25,0.00);
    coinPositions.emplace_back(0.30,0.00);
    coinPositions.emplace_back(0.35,0.00);
    coinPositions.emplace_back(0.40,0.00);

    coinPositions.emplace_back(-0.45,0.05);
    coinPositions.emplace_back(-0.35,0.05);
    coinPositions.emplace_back(-0.20,0.05);
    coinPositions.emplace_back(0.15,0.05);
    coinPositions.emplace_back(0.30,0.05);
    coinPositions.emplace_back(0.40,0.05);

    coinPositions.emplace_back(-0.45,0.10);
    coinPositions.emplace_back(-0.35,0.10);
    coinPositions.emplace_back(-0.30,0.10);
    coinPositions.emplace_back(-0.25,0.10);
    coinPositions.emplace_back(-0.20,0.10);
    coinPositions.emplace_back(-0.15,0.10);
    coinPositions.emplace_back(-0.10,0.10);
    coinPositions.emplace_back(-0.05,0.10);
    coinPositions.emplace_back(-0.00,0.10);
    coinPositions.emplace_back(0.05,0.10);
    coinPositions.emplace_back(0.10,0.10);
    coinPositions.emplace_back(0.15,0.10);
    coinPositions.emplace_back(0.20,0.10);
    coinPositions.emplace_back(0.25,0.10);
    coinPositions.emplace_back(0.30,0.10);
    coinPositions.emplace_back(0.40,0.10);

    coinPositions.emplace_back(-0.45,0.15);
    coinPositions.emplace_back(-0.30,0.15);
    coinPositions.emplace_back(-0.20,0.15);
    coinPositions.emplace_back(0.15,0.15);
    coinPositions.emplace_back(0.25,0.15);
    coinPositions.emplace_back(0.40,0.15);

    coinPositions.emplace_back(-0.45,0.20);
    coinPositions.emplace_back(-0.40,0.20);
    coinPositions.emplace_back(-0.35,0.20);
    coinPositions.emplace_back(-0.30,0.20);
    coinPositions.emplace_back(-0.20,0.20);
    coinPositions.emplace_back(-0.15,0.20);
    coinPositions.emplace_back(-0.10,0.20);
    coinPositions.emplace_back(-0.05,0.20);
    coinPositions.emplace_back(-0.00,0.20);
    coinPositions.emplace_back(0.05,0.20);
    coinPositions.emplace_back(0.10,0.20);
    coinPositions.emplace_back(0.15,0.20);
    coinPositions.emplace_back(0.25,0.20);
    coinPositions.emplace_back(0.30,0.20);
    coinPositions.emplace_back(0.35,0.20);

    for(auto i: coinPositions) {
        shared_ptr<Coin> coin = make_unique<Coin>(Coin(i));
        entities.push_back(coin);
    }

    // fruit placement
    vector<pair<double,double>> fruitPositions;
    fruitPositions.emplace_back(-0.45,-0.20);
    fruitPositions.emplace_back(0.40,0.20);

    for(auto i: fruitPositions) {
        shared_ptr<Fruit> fruit = make_unique<Fruit>(Fruit(i));
        entities.push_back(fruit);
    }

    shared_ptr<Pacman> pacman1 = make_unique<Pacman>(Pacman(make_pair(0.00,0.20)));
    entities.push_back(pacman1);
    pacman = pacman1;

    shared_ptr<Ghost> ghost1 = make_unique<Ghost>(Ghost(make_pair(-0.05,-0.05),"Red"));
    ghost1->moving = "Up";
    entities.push_back(ghost1);
    ghosts.push_back(ghost1);

    shared_ptr<Ghost> ghost2 = make_unique<Ghost>(Ghost(make_pair(-0.05,0.00),"Pink"));
    ghost2->moving = "Up";
    ghost2->chaseMode = true;
    entities.push_back(ghost2);
    ghosts.push_back(ghost2);

    shared_ptr<Ghost> ghost3 = make_unique<Ghost>(Ghost(make_pair(0.00,0.00),"Blue"));
    ghost3->moving = "Up";
    ghost3->chaseMode = true;
    entities.push_back(ghost3);
    ghosts.push_back(ghost3);

    shared_ptr<Ghost> ghost4 = make_unique<Ghost>(Ghost(make_pair(0.00,-0.05),"Orange"));
    ghost4->moving = "Up";
    entities.push_back(ghost4);
    ghosts.push_back(ghost4);

    score = make_shared<Score>(Score());

    fear = 0;
}

bool World::update(string direction, bool Check) {
    // update world time (only for begin)
    shared_ptr<StopWatch> stopWatch = StopWatch::getInstance();
    if(worldTime < 12000) {
        worldTime += stopWatch->getDeltaTime().count();
    }
    updateGhosts();

    // update fear
    if(fear > 0){
        fear--;
    }

    for(auto i: ghosts){
        if(i->state == 36){
            i->state = 0;
        }
        i->state += 3;
    }

    pair<float, float> currentPosition = pacman->getPosition();
    string currentMoving = pacman->moving;

    // check if pacman has a path to go to
    if(Check) {
        move(direction, 0.0005);
        if (!collisionCheck()) {
            pacman->setPosition(currentPosition);
            pacman->moving = currentMoving;
            return false;
        }
        pacman->setPosition(currentPosition);
        pacman->moving = currentMoving;
    }

    // move pacman if possible
    move(direction, 0.0001);
    if (!collisionCheck()) {
        pacman->setPosition(currentPosition);
        pacman->moving = currentMoving;
        return false;
    }

    // update pacman sprite state
    if(pacman->state == 36){
        pacman->state = 0;
    }
    pacman->state += 3;

    return true;
}

const vector<shared_ptr<Entity>> &World::getEntities() const {
    return entities;
}

int World::getLives() const {
    return lives;
}

const double World::getScore() const {
    return score->getCurrentScore();
}

void World::move(string direction, double multiplier) {
    // move pacman using time past
    shared_ptr<StopWatch> stopWatch = StopWatch::getInstance();
    if(direction == "Up"){
        pacman->setPosition(make_pair(pacman->getPosition().first, pacman->getPosition().second-multiplier*stopWatch->getDeltaTime().count()));
        pacman->moving = "Up";
    }
    else if(direction == "Left"){
        pacman->setPosition(make_pair(pacman->getPosition().first-multiplier*stopWatch->getDeltaTime().count(), pacman->getPosition().second));
        pacman->moving = "Left";
    }
    else if(direction == "Down"){
        pacman->setPosition(make_pair(pacman->getPosition().first, pacman->getPosition().second+multiplier*stopWatch->getDeltaTime().count()));
        pacman->moving = "Down";
    }
    else if(direction == "Right"){
        pacman->setPosition(make_pair(pacman->getPosition().first+multiplier*stopWatch->getDeltaTime().count(), pacman->getPosition().second));
        pacman->moving = "Right";
    }
}

void World::ghostMove(int ghost, string direction, double multiplier) {
// move the ghost using time past
    shared_ptr<StopWatch> stopWatch = StopWatch::getInstance();
    if(direction == "Up"){
        ghosts[ghost]->setPosition(make_pair(ghosts[ghost]->getPosition().first, ghosts[ghost]->getPosition().second-multiplier*stopWatch->getDeltaTime().count()));
        ghosts[ghost]->moving = "Up";
    }
    else if(direction == "Left"){
        ghosts[ghost]->setPosition(make_pair(ghosts[ghost]->getPosition().first-multiplier*stopWatch->getDeltaTime().count(), ghosts[ghost]->getPosition().second));
        ghosts[ghost]->moving = "Left";
    }
    else if(direction == "Down"){
        ghosts[ghost]->setPosition(make_pair(ghosts[ghost]->getPosition().first, ghosts[ghost]->getPosition().second+multiplier*stopWatch->getDeltaTime().count()));
        ghosts[ghost]->moving = "Down";
    }
    else if(direction == "Right"){
        ghosts[ghost]->setPosition(make_pair(ghosts[ghost]->getPosition().first+multiplier*stopWatch->getDeltaTime().count(), ghosts[ghost]->getPosition().second));
        ghosts[ghost]->moving = "Right";
    }
}

bool World::collisionCheck() {
    for(auto i: entities){
        // check if collision
        if(i->getType() != "Pacman"){
            if (pacman->getHitbox()[0] < i->getHitbox()[2] &&
                pacman->getHitbox()[2] > i->getHitbox()[0] &&
                pacman->getHitbox()[1] > i->getHitbox()[3] &&
                pacman->getHitbox()[3] < i->getHitbox()[1]){
                // wall collision
                if(i->getType() == "Wall"){
                    return false;
                }
                // update entities
                else if(i->getType() == "Coin" and !i->isEaten){
                    score->add(10);
                    i->isEaten = true;
                    i->setPosition(make_pair(i->getPosition().first+5, i->getPosition().second));
                }
                else if(i->getType() == "Fruit" and !i->isEaten){
                    score->add(50);
                    i->isEaten = true;
                    i->setPosition(make_pair(i->getPosition().first+5, i->getPosition().second));
                    fear = 500;
                }
            }
        }
    }
    return true;
}

bool World::ghostCollision(int ghost) {
    for(auto i: entities){
        // check if collision
        if(i->getType() != "Ghost"){
            if (ghosts[ghost]->getHitbox()[0] < i->getHitbox()[2] &&
                    ghosts[ghost]->getHitbox()[2] > i->getHitbox()[0] &&
                    ghosts[ghost]->getHitbox()[1] > i->getHitbox()[3] &&
                    ghosts[ghost]->getHitbox()[3] < i->getHitbox()[1]){
                // wall collision
                if(i->getType() == "Wall"){
                    return true;
                }
            }
        }
    }
    return false;
}

void World::updateGhosts() {
    shared_ptr<Random> random = Random::getInstance();
    if(worldTime > 5000){
        ghosts[0]->chaseMode = true;
    }
    if(worldTime > 10000){
        ghosts[3]->chaseMode = true;
    }
    // ghost AI
    for(int i = 0; i < ghosts.size(); i++){
        // help ghost out of cage if necessary
        if(ghosts[i]->getPosition().first < 0.05 and ghosts[i]->getPosition().first > 0.00 and
           ghosts[i]->getPosition().second < 0.05 and ghosts[i]->getPosition().second > 0.00){
            ghosts[i]->moving = "Up";
        }
        if(ghosts[i]->chaseMode){
            // respawn when ghost is dead
            if(ghosts[i]->spawn == 0){
                ghosts[i]->moving = "Up";
                ghosts[i]->setPosition(make_pair(-0.05,-0.05));
            }
            ghosts[i]->spawn++;
            pair<float, float> currentPosition = ghosts[i]->getPosition();
            string currentMoving = ghosts[i]->moving;
            if(ghosts[i]->spawn > 500 and ghosts[i]->lastSwitched > 500) {
                vector<string> possibleMoves;
                if (currentMoving == "Up" or currentMoving == "Down" and ghostPossibleMove(i, "Left")) {
                    possibleMoves.push_back("Left");
                }
                if (currentMoving == "Up" or currentMoving == "Down" and ghostPossibleMove(i, "Right")) {
                    possibleMoves.push_back("Right");
                }
                if (currentMoving == "Left" or currentMoving == "Right" and ghostPossibleMove(i, "Up")) {
                    possibleMoves.push_back("Up");
                }
                if (currentMoving == "Left" or currentMoving == "Right" and ghostPossibleMove(i, "Down")) {
                    possibleMoves.push_back("Down");
                }
                if (possibleMoves.size() == 2) {
                    ghosts[i]->lastSwitched = 0;
                    if (random->getRandomNumber() >= 0.5) {
                        ghostMove(i, possibleMoves[0], 0.0001);
                    } else {
                        ghostMove(i, possibleMoves[1], 0.0001);
                    }
                }
                else if (possibleMoves.size() == 1) {
                    ghosts[i]->lastSwitched = 0;
                    ghostMove(i, possibleMoves[0], 0.0001);
                }
                else {
                    ghostMove(i, currentMoving, 0.0001);
                }
            }
            else{
                ghosts[i]->lastSwitched++;
                ghostMove(i,currentMoving, 0.0001);
                if(ghostCollision(i)){
                    ghosts[i]->setPosition(currentPosition);
                    ghosts[i]->moving = currentMoving;
                    calculateMove(i,currentMoving);
                }
            }
        }
    }
}

string World::calculateMove(int ghost, string currentMoving) {
    shared_ptr<Random> random = Random::getInstance();
    int i = ghost;
    vector<string> possibleMoves;
    if(currentMoving == "Up" or currentMoving == "Down" and ghostPossibleMove(i, "Left")){
        possibleMoves.push_back("Left");
    }
    if(currentMoving == "Up" or currentMoving == "Down" and ghostPossibleMove(i, "Right")){
        possibleMoves.push_back("Right");
    }
    if(currentMoving == "Left" or currentMoving == "Right" and ghostPossibleMove(i, "Up")){
        possibleMoves.push_back("Up");
    }
    if(currentMoving == "Left" or currentMoving == "Right" and ghostPossibleMove(i, "Down")){
        possibleMoves.push_back("Down");
    }
    if(possibleMoves.size() == 2){
        if(random->getRandomNumber() >= 0.5){
            ghostMove(i,possibleMoves[0], 0.0001);
        }
        else{
            ghostMove(i,possibleMoves[1], 0.0001);
        }
    }
    else if(possibleMoves.size() == 1){
        ghostMove(i,possibleMoves[0], 0.0001);
    }
    else{
        string move = "Up";
        float manhattanDistance = calculateManhattanDistance(i, "Up");
        if(calculateManhattanDistance(i, "Left") < manhattanDistance){
            manhattanDistance = calculateManhattanDistance(i, "Left");
            move = "Left";
        }
        if(calculateManhattanDistance(i, "Down") < manhattanDistance){
            manhattanDistance = calculateManhattanDistance(i, "Down");
            move = "Down";
        }
        if(calculateManhattanDistance(i, "Right") < manhattanDistance){
            move = "Right";
        }
        ghostMove(i,move, 0.0001);
    }
}

bool World::ghostPossibleMove(int ghost, string direction) {
    pair<float, float> currentPosition = ghosts[ghost]->getPosition();
    string currentMoving = ghosts[ghost]->moving;
    ghostMove(ghost, direction, 0.0003);
    if(ghostCollision(ghost)){
        ghosts[ghost]->setPosition(currentPosition);
        ghosts[ghost]->moving = currentMoving;
        return false;
    }
    ghosts[ghost]->setPosition(currentPosition);
    ghosts[ghost]->moving = currentMoving;
    return true;
}

float World::calculateManhattanDistance(int ghost, string direction) {
    if(ghostPossibleMove(ghost, direction)){
        return abs(pacman->getPosition().first-ghosts[ghost]->getPosition().first) +
                abs(pacman->getPosition().second-ghosts[ghost]->getPosition().second);
    }
    else{
        return 100;
    }
}

bool World::getFear() const {
    if(fear == 0){
        return false;
    }
    return true;
}

void World::setLives(int lives) {
    World::lives = lives;
}

void World::setScore(const shared_ptr<Score> &score) {
    World::score = score;
}

bool World::levelFinished() {
    for(auto i: entities){
        if(i->getType() == "Coin" and !i->isEaten){
            return false;
        }
        else if(i->getType() == "Fruit" and !i->isEaten){
            return false;
        }
    }
    return true;
}

/*
bool World::check(string direction) {
    pair<float,float> currentPosition = pacman->getPosition();
    string currentMoving = pacman->moving;
    move(direction, 0.05);
    if(!collisionCheck()) {
        pacman->setPosition(currentPosition);
        pacman->moving = currentMoving;
        return false;
    }
    pacman->setPosition(currentPosition);
    pacman->moving = currentMoving;
    return true;
}
 */
