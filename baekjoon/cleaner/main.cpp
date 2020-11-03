#include <iostream>


int n, m;
int room[51][51] = {0};

int direction[4][2] = {
        {0,  -1},   // up
        {1,  0},    // right
        {0,  1},    // bottom
        {-1, 0},     // left
};

int clean(int r, int c, int dir) {

    const int ToClean = 0;
    const int Wall = 1;
    const int Cleaned = 2;

    int cleaned = 0;
    bool canMove = true;
    int nextDir;
    int stopCount = 0;
    while (canMove) {
        int cur = room[r][c];
        if (cur == ToClean) {
            room[r][c] = Cleaned;
            ++cleaned;
        }

        // left rotate and check
        if (stopCount == 4) {
            int reverseDir = (dir + 2) % 4; // find reverse
            int *dt = direction[reverseDir];
            int nextRow = r + dt[1];
            int nextCol = c + dt[0];
            stopCount = 0;
            if (room[nextRow][nextCol] == Wall) {
                canMove = false;
            } else {
                r = nextRow;
                c = nextCol;
            }

            continue;
        }

        nextDir = (dir - 1 < 0) ? 3 : (dir - 1);    // find left
        int *dt = direction[nextDir];
        int nextRow = r + dt[1];
        int nextCol = c + dt[0];
        if (room[nextRow][nextCol] == ToClean) {
            r = nextRow;
            c = nextCol;
            dir = nextDir;
            stopCount = 0;
        } else {
            dir = nextDir;
            ++stopCount;
        }
    }

    return cleaned;
}

int main() {
    int startRow, startCol;
    int currentDir;

    std::cin >> n >> m;
    std::cin >> startRow >> startCol >> currentDir;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> room[i][j];
        }
    }

    std::cout << clean(startRow, startCol, currentDir) << std::endl;

    return 0;
}