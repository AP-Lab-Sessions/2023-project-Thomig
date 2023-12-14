#include "Score.h"

void Score::add(int x) {
    currentScore += x;
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

    sort(scores.begin(), scores.end(), std::greater<int>());

    ofstream myfile;

    myfile.open ("../Logic Library/ScoreBoard.txt");
    myfile << scores[0] << ' ' << scores[1] << ' ' << scores[2] << ' ' << scores[3] << ' ' << scores[4];

    myfile.close();
}
vector<int> Score::getScoreBoard() {
    vector<int> scores;

    ifstream inputFile("../Logic Library/ScoreBoard.txt");

    string line;
    if (getline(inputFile, line)) {
        istringstream iss(line);
        int score;

        while (iss >> score) {
            scores.push_back(score);
        }
    }

    inputFile.close();
    return scores;
}
