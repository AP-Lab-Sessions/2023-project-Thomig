#include "Score.h"

void Score::add(int x) {
    currentScore += x;
}

void Score::dec() {
    if(currentScore >= 1) {
        currentScore -= 1;
    }
}

int Score::getCurrentScore() const {
    return currentScore;
}

void Score::addToScoreBoard() {
    vector<int> scores = getScoreBoard();
    for(int i = 0; i < 5-scores.size(); i++){
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
    if(currentScore > smallestValue){
        scores[smallestValueLoc] = currentScore;
    }

    sort(scores.begin(), scores.end(), greater<int>());

    ofstream myfile;

    try {
        // check if file is found
        myfile.open("../Logic Library/ScoreBoard.txt");

        if (!myfile.is_open()) {
            throw runtime_error("File ScoreBoard.txt is not found or unable to open");
        }
        myfile << scores[0] << ' ' << scores[1] << ' ' << scores[2] << ' ' << scores[3] << ' ' << scores[4];

        myfile.close();
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

vector<int> Score::getScoreBoard() {
    vector<int> scores;
    const string filePath = "../Logic Library/ScoreBoard.txt";

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
            int score;

            while (iss >> score) {
                scores.push_back(score);
            }
        }

        inputFile.close();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return scores;
}

Score::Score() {}
