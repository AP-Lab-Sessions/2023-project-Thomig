//
// Created by thomas on 1/12/23.
//

#include "World.h"

World::World() {
    // set up the walls
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
    bool disableCoins = false;  // disable coins to complete level fast for testing
    int x = 1;
    if(disableCoins){
        x = 20;
    }
    // coins per layer placement
    coinPositions.emplace_back(-0.40*x,-0.20);
    coinPositions.emplace_back(-0.35*x,-0.20);
    coinPositions.emplace_back(-0.30*x,-0.20);
    coinPositions.emplace_back(-0.20*x,-0.20);
    coinPositions.emplace_back(-0.15*x,-0.20);
    coinPositions.emplace_back(-0.10*x,-0.20);
    coinPositions.emplace_back(-0.05*x,-0.20);
    coinPositions.emplace_back(-0.00*x,-0.20*x);
    coinPositions.emplace_back(0.05*x,-0.20);
    coinPositions.emplace_back(0.10*x,-0.20);
    coinPositions.emplace_back(0.15*x,-0.20);
    coinPositions.emplace_back(0.25*x,-0.20);
    coinPositions.emplace_back(0.30*x,-0.20);
    coinPositions.emplace_back(0.35*x,-0.20);
    coinPositions.emplace_back(0.40*x,-0.20);

    coinPositions.emplace_back(-0.45*x,-0.15);
    coinPositions.emplace_back(-0.30*x,-0.15);
    coinPositions.emplace_back(-0.20*x,-0.15);
    coinPositions.emplace_back(0.15*x,-0.15);
    coinPositions.emplace_back(0.25*x,-0.15);
    coinPositions.emplace_back(0.40*x,-0.15);

    coinPositions.emplace_back(-0.45*x,-0.10);
    coinPositions.emplace_back(-0.35*x,-0.10);
    coinPositions.emplace_back(-0.30*x,-0.10);
    coinPositions.emplace_back(-0.25*x,-0.10);
    coinPositions.emplace_back(-0.20*x,-0.10);
    coinPositions.emplace_back(-0.15*x,-0.10);
    coinPositions.emplace_back(-0.10*x,-0.10);
    coinPositions.emplace_back(-0.05*x,-0.10);
    coinPositions.emplace_back(-0.00,-0.10*x);
    coinPositions.emplace_back(0.05*x,-0.10);
    coinPositions.emplace_back(0.10*x,-0.10);
    coinPositions.emplace_back(0.15*x,-0.10);
    coinPositions.emplace_back(0.20*x,-0.10);
    coinPositions.emplace_back(0.25*x,-0.10);
    coinPositions.emplace_back(0.30*x,-0.10);
    coinPositions.emplace_back(0.40*x,-0.10);

    coinPositions.emplace_back(-0.45*x,-0.05);
    coinPositions.emplace_back(-0.35*x,-0.05);
    coinPositions.emplace_back(-0.20*x,-0.05);
    coinPositions.emplace_back(0.15*x,-0.05);
    coinPositions.emplace_back(0.30*x,-0.05);
    coinPositions.emplace_back(0.40*x,-0.05);

    coinPositions.emplace_back(-0.45*x,0.00);
    coinPositions.emplace_back(-0.40*x,0.00);
    coinPositions.emplace_back(-0.35*x,0.00);
    coinPositions.emplace_back(-0.30*x,0.00);
    coinPositions.emplace_back(-0.25*x,0.00);
    coinPositions.emplace_back(-0.20*x,0.00);
    coinPositions.emplace_back(0.15*x,0.00);
    coinPositions.emplace_back(0.20*x,0.00);
    coinPositions.emplace_back(0.25*x,0.00);
    coinPositions.emplace_back(0.30*x,0.00);
    coinPositions.emplace_back(0.35*x,0.00);
    coinPositions.emplace_back(0.40*x,0.00);

    coinPositions.emplace_back(-0.45*x,0.05);
    coinPositions.emplace_back(-0.35*x,0.05);
    coinPositions.emplace_back(-0.20*x,0.05);
    coinPositions.emplace_back(0.15*x,0.05);
    coinPositions.emplace_back(0.30*x,0.05);
    coinPositions.emplace_back(0.40*x,0.05);

    coinPositions.emplace_back(-0.45*x,0.10);
    coinPositions.emplace_back(-0.35*x,0.10);
    coinPositions.emplace_back(-0.30*x,0.10);
    coinPositions.emplace_back(-0.25*x,0.10);
    coinPositions.emplace_back(-0.20*x,0.10);
    coinPositions.emplace_back(-0.15*x,0.10);
    coinPositions.emplace_back(-0.10*x,0.10);
    coinPositions.emplace_back(-0.05*x,0.10);
    coinPositions.emplace_back(-0.00*x,0.10*x);
    coinPositions.emplace_back(0.05*x,0.10);
    coinPositions.emplace_back(0.10*x,0.10);
    coinPositions.emplace_back(0.15*x,0.10);
    coinPositions.emplace_back(0.20*x,0.10);
    coinPositions.emplace_back(0.25*x,0.10);
    coinPositions.emplace_back(0.30*x,0.10);
    coinPositions.emplace_back(0.40*x,0.10);

    coinPositions.emplace_back(-0.45*x,0.15);
    coinPositions.emplace_back(-0.30*x,0.15);
    coinPositions.emplace_back(-0.20*x,0.15);
    coinPositions.emplace_back(0.15*x,0.15);
    coinPositions.emplace_back(0.25*x,0.15);
    coinPositions.emplace_back(0.40*x,0.15);

    coinPositions.emplace_back(-0.45*x,0.20);
    coinPositions.emplace_back(-0.40*x,0.20);
    coinPositions.emplace_back(-0.35*x,0.20);
    coinPositions.emplace_back(-0.30*x,0.20);
    coinPositions.emplace_back(-0.20*x,0.20);
    coinPositions.emplace_back(-0.15*x,0.20);
    coinPositions.emplace_back(-0.10*x,0.20);
    coinPositions.emplace_back(-0.05*x,0.20);
    coinPositions.emplace_back(-0.00*x,0.20*x);
    coinPositions.emplace_back(0.05*x,0.20);
    coinPositions.emplace_back(0.10*x,0.20);
    coinPositions.emplace_back(0.15*x,0.20);
    coinPositions.emplace_back(0.25*x,0.20);
    coinPositions.emplace_back(0.30*x,0.20);
    coinPositions.emplace_back(0.35*x,0.20);

    for(auto i: coinPositions) {
        shared_ptr<Coin> coin = make_unique<Coin>(Coin(i));
        if(disableCoins) {
            coin->isEaten = true;
        }
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
}

bool World::update(string direction, bool Check) {
    // update world time (only for begin)
    shared_ptr<StopWatch> stopWatch = StopWatch::getInstance();
    shared_ptr<LevelStats> levelStats = LevelStats::getInstance();
    worldTime += stopWatch->getDeltaTime().count();

    // decrease score overtime
    if(worldTime%50 == 0){
        levelStats->decScore();
    }

    if(!Check){
        updateGhosts();
    }

    coinPickUpInterval -= 0.002;

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

void World::ghostMove(int ghost, const string& direction, double multiplier) {
    // move the ghost using time past and difficulty level
    shared_ptr<LevelStats> levelStats = LevelStats::getInstance();
    double dsi = pow(1.05, levelStats->getDifficulty());    // difficulty speed increase (+0.5% per level inc)
    if(ghosts[ghost]->fear != 0){
        dsi *= 0.8;    // ghosts 20% slower in fear mode
    }
    shared_ptr<StopWatch> stopWatch = StopWatch::getInstance();
    if(direction == "Up"){
        ghosts[ghost]->setPosition(make_pair(ghosts[ghost]->getPosition().first, ghosts[ghost]->getPosition().second-multiplier*stopWatch->getDeltaTime().count()*dsi));
        ghosts[ghost]->moving = "Up";
    }
    else if(direction == "Left"){
        ghosts[ghost]->setPosition(make_pair(ghosts[ghost]->getPosition().first-multiplier*stopWatch->getDeltaTime().count()*dsi, ghosts[ghost]->getPosition().second));
        ghosts[ghost]->moving = "Left";
    }
    else if(direction == "Down"){
        ghosts[ghost]->setPosition(make_pair(ghosts[ghost]->getPosition().first, ghosts[ghost]->getPosition().second+multiplier*stopWatch->getDeltaTime().count()*dsi));
        ghosts[ghost]->moving = "Down";
    }
    else if(direction == "Right"){
        ghosts[ghost]->setPosition(make_pair(ghosts[ghost]->getPosition().first+multiplier*stopWatch->getDeltaTime().count()*dsi, ghosts[ghost]->getPosition().second));
        ghosts[ghost]->moving = "Right";
    }
}

bool World::collisionCheck() {
    shared_ptr<LevelStats> levelStats = LevelStats::getInstance();
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
                    levelStats->addScore(floor(coinPickUpInterval*10));
                    coinPickUpInterval = 1;
                    i->isEaten = true;
                    i->setPosition(make_pair(i->getPosition().first+5, i->getPosition().second));
                }
                else if(i->getType() == "Fruit" and !i->isEaten){
                    levelStats->addScore(50);
                    i->isEaten = true;
                    i->setPosition(make_pair(i->getPosition().first+5, i->getPosition().second));
                    for(auto i: ghosts){
                        i->fear = ceil(500 * pow(0.8, levelStats->getDifficulty()));
                    }
                }
            }
        }
    }
    return true;
}

bool World::ghostCollision(int ghost) {
    shared_ptr<LevelStats> levelStats = LevelStats::getInstance();
    for(auto i: entities){
        // check if collision
        if(i->getType() != "Ghost"){
            // check if wall collision
            if (ghosts[ghost]->getHitbox()[0] < i->getHitbox()[2] &&
                    ghosts[ghost]->getHitbox()[2] > i->getHitbox()[0] &&
                    ghosts[ghost]->getHitbox()[1] > i->getHitbox()[3] &&
                    ghosts[ghost]->getHitbox()[3] < i->getHitbox()[1]){
                // wall collision
                if(i->getType() == "Wall"){
                    return true;
                }
            }
            // check if pacman collision
            if (ghosts[ghost]->getSmallHitbox()[0] < i->getHitbox()[2] &&
                ghosts[ghost]->getSmallHitbox()[2] > i->getHitbox()[0] &&
                ghosts[ghost]->getSmallHitbox()[1] > i->getHitbox()[3] &&
                ghosts[ghost]->getSmallHitbox()[3] < i->getHitbox()[1]){

                if(i->getType() == "Pacman"){
                    if(ghosts[ghost]->fear != 0){
                        ghosts[ghost]->spawn = 0;
                        cout << "ghost " << ghost << " fear set to 0" << endl;
                        cout << "ghost " << ghost << " lastdead: " << ghosts[ghost]->lastDead << endl;
                        ghosts[ghost]->fear = 0;
                        ghosts[ghost]->lastDead = 0;
                        levelStats->addScore(100);
                    }
                    else if(ghosts[ghost]->lastDead > 5
                     ){
                        levelStats->decLives();
                        cout << "Dead by ghost " << ghost << endl << endl << endl;
                        pacman->setPosition(make_pair(0.00,0.20));
                        ghosts[0]->setPosition(make_pair(-0.05,-0.05));
                        ghosts[1]->setPosition(make_pair(-0.05,0.00));
                        ghosts[2]->setPosition(make_pair(0.00,0.00));
                        ghosts[3]->setPosition(make_pair(0.00,-0.05));
                    }
                }
            }
        }
    }
    return false;
}

void World::updateGhosts() {
    shared_ptr<LevelStats> levelStats = LevelStats::getInstance();
    shared_ptr<Random> random = Random::getInstance();
    if(worldTime > 5000){
        ghosts[0]->chaseMode = true;
    }
    if(worldTime > 10000){
        ghosts[3]->chaseMode = true;
    }
    // ghost AI
    for(int i = 0; i < ghosts.size(); i++){
        ghosts[i]->lastDead++;
        cout << "ghost " << i << " fear: " << ghosts[i]->fear << endl;
        cout << "ghost " << i << " spawn: " << ghosts[i]->spawn << endl;
        // update fear
        if(ghosts[i]->fear != 0){
            if(ghosts[i]->fear == ceil(500 * pow(0.8, levelStats->getDifficulty()))){
                ghosts[i]->moving = reverseDirection(ghosts[i]->moving);
            }
            ghosts[i]->fear--;
        }
        // help ghost out of cage if necessary
        if(ghosts[i]->getPosition().first < 0.05 and ghosts[i]->getPosition().first > 0.00 and
           ghosts[i]->getPosition().second < 0.05 and ghosts[i]->getPosition().second > 0.00){
            ghosts[i]->moving = "Up";
        }
        // make sure ghosts don't get stuck in walls
        if(worldTime%10 == 0){
            ghosts[i]->positionSave = ghosts[i]->getPosition();
        }
        if(ghostCollision(i)){
            ghosts[i]->setPosition(ghosts[i]->positionSave);
        }
        if(ghosts[i]->chaseMode){
            // respawn when ghost is dead
            if(ghosts[i]->spawn == 0){
                ghosts[i]->moving = "Up";
                ghosts[i]->setPosition(make_pair(-0.05,-0.05));
            }
            ghosts[i]->spawn++;
            // calculate direction
            pair<float, float> currentPosition = ghosts[i]->getPosition();
            string currentMoving = ghosts[i]->moving;
            if(ghosts[i]->spawn > 500 and ghosts[i]->lastSwitched > 200) {
                vector<string> possibleMoves = getPossibleMoves(i, currentMoving);
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

void World::calculateMove(int ghost, const string& currentMoving) {
    shared_ptr<Random> random = Random::getInstance();
    int i = ghost;
    vector<string> possibleMoves = getPossibleMoves(ghost, currentMoving);
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
        // ghost chooses shortest Manhattan distance to pacman (reverse when in fear)
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
        if(ghosts[ghost]->fear != 0){
            move = reverseDirection(move);
        }
        ghostMove(i,move, 0.0001);
    }
}

vector<string> World::getPossibleMoves(int ghost, const string& currentMoving){
    // get possible moves using current direction
    vector<string> possibleMoves;
    if(currentMoving == "Up" or currentMoving == "Down" and ghostPossibleMove(ghost, "Left")){
        possibleMoves.emplace_back("Left");
    }
    if(currentMoving == "Up" or currentMoving == "Down" and ghostPossibleMove(ghost, "Right")){
        possibleMoves.emplace_back("Right");
    }
    if(currentMoving == "Left" or currentMoving == "Right" and ghostPossibleMove(ghost, "Up")){
        possibleMoves.emplace_back("Up");
    }
    if(currentMoving == "Left" or currentMoving == "Right" and ghostPossibleMove(ghost, "Down")){
        possibleMoves.emplace_back("Down");
    }
    return possibleMoves;
}

bool World::ghostPossibleMove(int ghost, string direction) {    // check if ghost can move in direction
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
    // calculate manhattan distance between ghost and pacman
    if(ghostPossibleMove(ghost, std::move(direction))){
        return abs(pacman->getPosition().first-ghosts[ghost]->getPosition().first) +
                abs(pacman->getPosition().second-ghosts[ghost]->getPosition().second);
    }
    else{
        return 100;
    }
}

string World::reverseDirection(const string& direction) {
    // return opposite direction
    if(direction == "Up"){
        return "Down";
    }
    else if(direction == "Left"){
        return "Right";
    }
    else if(direction == "Right"){
        return "Left";
    }
    else{
        return "Up";
    }
}

bool World::levelFinished() {
    shared_ptr<LevelStats> levelStats = LevelStats::getInstance();
    for(auto i: entities){
        if(i->getType() == "Coin" and !i->isEaten){
            return false;
        }
        else if(i->getType() == "Fruit" and !i->isEaten){
            return false;
        }
    }
    levelStats->increaseDifficulty();

    // bonus points for level finish
    levelStats->addScore(200);

    return true;
}
