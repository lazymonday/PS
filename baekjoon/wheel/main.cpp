#include <iostream>
#include <string>

using namespace std;

string wheels[4];
int numOfMoves = 0;

void rotateWheel(int no, bool b, bool pBoolean[4]);

int calculateScore() {
    int score = 0;
    for (int i = 0; i < 4; ++i) {
        if (wheels[i][0] == '1') {
            score += (1 << i);
        }
    }

    return score;
}


int main() {

    for (int i = 0; i < 4; ++i) {
        std::cin >> wheels[i];
    }

    int wheelNo;
    int rotateDir;
    std::cin >> numOfMoves;
    for (int i = 0; i < numOfMoves; ++i) {
        std::cin >> wheelNo;
        std::cin >> rotateDir;
        --wheelNo;
        bool visited[4] = {false};
        rotateWheel(wheelNo, rotateDir == 1, visited);
    }

    cout << calculateScore() << endl;
    return 0;
}

void rotateWheel(int wheelNo, bool isClockwise, bool visited[4]) {

    if (wheelNo < 0 || wheelNo > 3 || visited[wheelNo]) {
        return;
    }

    // check left
    visited[wheelNo] = true;
    if (wheelNo - 1 >= 0 && wheels[wheelNo - 1][2] != wheels[wheelNo][6]) {
        rotateWheel(wheelNo - 1, !isClockwise, visited);
    }

    if (wheelNo + 1 <= 3 && wheels[wheelNo + 1][6] != wheels[wheelNo][2]) {
        rotateWheel(wheelNo + 1, !isClockwise, visited);
    }

    if (isClockwise) {
        char last = wheels[wheelNo][7];
        wheels[wheelNo].erase(7);
        wheels[wheelNo].insert(wheels[wheelNo].begin(), last);
    } else {
        wheels[wheelNo].push_back(wheels[wheelNo][0]);
        wheels[wheelNo] = wheels[wheelNo].substr(1);
    }
}
