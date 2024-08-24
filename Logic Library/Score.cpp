//
// Created by thomas on 8/08/24.
//

#include "Score.h"

Score::Score() {}

void Score::update() {}

void Score::increaseScore(int s) {
    this->score += s;
}

void Score::decreaseScore() {
    if (score > 0) {
        score--;
    }
}

int Score::getScore() {
    return score;
}

void Score::resetScore() {
    score = 0;
}

void Score::addToScoreBoard() {
    vector<int> scores = getScoreBoard();
    for (int i = 0; i < 5 - scores.size(); i++) {
        scores.push_back(0);
    }

    int smallestValue = scores[0];
    int smallestValueLoc = 0;

    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] < smallestValue) {
            smallestValueLoc = i;
            smallestValue = scores[i];
        }
    }
    if (score > smallestValue) {
        scores[smallestValueLoc] = score;
    }

    sort(scores.begin(), scores.end(), greater<int>());

    ofstream myFile;

    try {
        // check if file is found
        myFile.open("../ScoreBoard.txt");

        if (!myFile.is_open()) {
            throw runtime_error("File ScoreBoard.txt is not found or unable to open");
        }
        myFile << scores[0] << ' ' << scores[1] << ' ' << scores[2] << ' ' << scores[3] << ' ' << scores[4];

        myFile.close();
    }
    catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

vector<int> Score::getScoreBoard() {
    vector<int> scores;
    const string filePath = "../ScoreBoard.txt";

    try {
        // check if file is opened
        ifstream inputFile(filePath);

        if (!inputFile.is_open()) {
            throw runtime_error("Error: Unable to open file ScoreBoard.txt");
        }

        // read scores from file
        string line;
        if (getline(inputFile, line)) {
            istringstream iss(line);
            int currentScore;

            while (iss >> currentScore) {
                scores.push_back(currentScore);
            }
        }

        inputFile.close();
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
    }
    return scores;
}
