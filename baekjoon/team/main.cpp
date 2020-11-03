#include <iostream>
#include <algorithm>

int n;  // [1, n]
int score[21][21];  // zero is just margin
int half;
int teamA[10] = {-1};
int minDiff = 987654321;

int calculate(int team[10]) {

    int teamScore = 0;

    for(int k = 1; k < half; ++k) {
        int i = team[k];

        for(int l = 0; l < k; ++l) {
            int j = team[l];
            teamScore += score[i][j];
            teamScore += score[j][i];
        }
    }

    return teamScore;
}

void findMinDiff(int start, int choose) {
    if (start == n) {
        if (choose == half) {
            // calculate team value
            int teamB[10] = {-1};
            int a = 0, b = 0;

            for(int i = 0; i < n; ++i) {
                if(teamA[a] == i) {
                    ++a;
                    continue;
                }

                teamB[b++] = i;
            }

            minDiff = std::min(minDiff, abs(calculate(teamA) - calculate(teamB)));
        }
        return;
    }

    teamA[choose] = start;
    findMinDiff(start + 1, choose + 1);
    teamA[choose] = -1;
    findMinDiff(start + 1, choose);
}

int main() {

    std::cin >> n;
    half = n / 2;   // n is always even
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> score[i][j];
        }
    }

    findMinDiff(0, 0);
    std::cout << minDiff << std::endl;
    return 0;
}
