#include <iostream>
#include <algorithm>
#include <cassert>

int n, m;
int cctvCount = 0;
int office[8][8];
int cctvLoc[8][2];
int cctv[8];  // direction

int fillCCTVSight(int *copiedOffice) {

    static const int direction[4][2] = {
            {1,  0},     // right = 0
            {0,  -1},    // up = 1
            {-1, 0},    // left = 2
            {0,  1}      // bottom = 3
    };

    static const int cctvDir[][4][4] = {
            {{-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}},
            {{0,  -1, -1, -1}, {1,  -1, -1, -1}, {2,  -1, -1, -1}, {3,  -1, -1, -1}},   // CCTV 1
            {{0,  2,  -1, -1}, {1,  3,  -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}},   // CCTV 2
            {{0,  1,  -1, -1}, {1,  2,  -1, -1}, {2,  3,  -1, -1}, {3,  0,  -1, -1}},   // CCTV3
            {{0,  1,  2,  -1}, {1,  2,  3,  -1}, {2,  3,  0,  -1}, {3,  0,  1,  -1}},    // CCTV4
            {{0,  1,  2,  3},  {0,  1,  2,  3},  {0,  1,  2,  3},  {0,  1,  2,  3}}     // CCTV5
    };

    static const int Wall = 6;
    static const int nonBlindSpot = -1;

    for (int i = 0; i < cctvCount; ++i) {
        int r = cctvLoc[i][0];
        int c = cctvLoc[i][1];
        int kind = copiedOffice[r * m + c];
        int cctvToward = cctv[i];

        assert(kind >= 0 && kind <= 5 && cctvToward <= 3 && cctvToward >= 0);

        for (int dirIndex = 0; dirIndex < 4; ++dirIndex) {
            int dir = cctvDir[kind][cctvToward][dirIndex];
            if (dir == -1) {
                break;
            }

            const int *dt = direction[dir];
            int nextR = r + dt[1];
            int nextC = c + dt[0];

            while (nextR >= 0 && nextR < n &&
                   nextC >= 0 && nextC < m) {
                int next = copiedOffice[nextR * m + nextC];
                if (next == 0) {
                    copiedOffice[nextR * m + nextC] = nonBlindSpot;
                } else if (next == Wall) {
                    break;
                }

                nextR += dt[1];
                nextC += dt[0];
            }
        }
    }
}

int countBlindSpot(int *copied) {
    int numOfBlinds = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (copied[i * m + j] == 0) {
                numOfBlinds++;
            }
        }
    }

    return numOfBlinds;
}

int nextDir(int dir) {
    return (dir + 1) % 4;
}

int findMinimalBlindSpot(int count, int choose) {

    if (choose == count) {
        int *cloned = new int[m * n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cloned[i * m + j] = office[i][j];
            }
        }

        fillCCTVSight(cloned);
        return countBlindSpot(cloned);
    }

    int minBlind = 987654321;
    for (int i = 0; i < 4; ++i) {
        cctv[choose] = nextDir(cctv[choose]);
        minBlind = std::min(minBlind, findMinimalBlindSpot(count, choose + 1));
    }

    return minBlind;
}

int main() {
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> office[i][j];
            if (office[i][j] > 0 && office[i][j] < 6) {
                cctv[cctvCount] = 0;
                cctvLoc[cctvCount][0] = i;
                cctvLoc[cctvCount][1] = j;
                cctvCount++;
            }
        }
    }

    std::cout << findMinimalBlindSpot(cctvCount, 0) << std::endl;
    return 0;
}