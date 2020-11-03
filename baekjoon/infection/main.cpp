#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int n;
int m;
const int maxSize = 8;


void percolate(int board[maxSize][maxSize]);

int selectWallAndPercolate(int selected, int tried, int board[maxSize][maxSize]);


std::queue<std::pair<int, int>> queue;

void printBoard(int board[maxSize][maxSize]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << board[i][j];
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int countSafetyArea(int board[maxSize][maxSize]) {

    int zeroCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 0) {
                ++zeroCount;
            }
        }
    }

    return zeroCount;
}


int selectWallAndPercolate(int selected, int tried, int board[maxSize][maxSize]) {

    if (selected == 3) {
        int tempBoard[maxSize][maxSize];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                tempBoard[i][j] = board[i][j];
            }
        }

        percolate(tempBoard);
        return countSafetyArea(tempBoard);
    } else if (tried > maxSize * maxSize) {
        return -1;
    }

    int maxSafetyArea = 0;

    for (int i = tried; i < n * m; ++i) {
        int row = i / m;
        int col = i % m;
        if (board[row][col] != 0) {
            continue;
        }

        board[row][col] = 8;
        maxSafetyArea = std::max(selectWallAndPercolate(selected + 1, tried + 1, board), maxSafetyArea);
        board[row][col] = 0;
        maxSafetyArea = std::max(selectWallAndPercolate(selected, tried + 1, board), maxSafetyArea);
        break;
    }

    return maxSafetyArea;
}

void percolate(int board[maxSize][maxSize]) {

    const static int direction[4][2] = {{1,  0},    // right
                                        {0,  1},    // bottom
                                        {-1, 0},    // left
                                        {0,  -1}};  // up

    std::queue<std::pair<int, int>> newQueue(queue);
    while (!newQueue.empty()) {
        const std::pair<int, int> &pollutant = newQueue.front();
        newQueue.pop();
        for (int i = 0; i < 4; ++i) {
            if (board[pollutant.second][pollutant.first] != 2) {
                std::cout << "its weired\n";
                continue;
            }

            int x = pollutant.first + direction[i][0];
            int y = pollutant.second + direction[i][1];

            if (x < 0 || x >= m) {
                continue;
            }
            if (y < 0 || y >= n) {
                continue;
            }

            if (board[y][x] == 0) {
                board[y][x] = 2;
                newQueue.push(std::make_pair(x, y));
            }
        }
    }
}

int main() {

    int board[maxSize][maxSize];

    std::cin >> n;
    std::cin >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> board[i][j];
            if (board[i][j] == 2) {
                queue.push(std::make_pair(j, i));
            }
        }
    }

    std::cout << selectWallAndPercolate(0, 0, board) << std::endl;

    return 0;
}