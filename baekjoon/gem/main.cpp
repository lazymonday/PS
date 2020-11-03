#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>


int n;
int m;

class Board {
public:
    Board(const Board &rhs) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                board[i][j] = rhs.board[i][j];
            }
        }

        red[0] = rhs.red[0];
        red[1] = rhs.red[1];
        blue[0] = rhs.blue[0];
        blue[1] = rhs.blue[1];
        hole[0] = rhs.hole[0];
        hole[1] = rhs.hole[1];
        prevDir = -99;
        movesFromRoot = rhs.movesFromRoot;
        redExist = false, blueExist = false;
    }

    Board(int n, int m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                board[i][j] = 0;
            }
        }
        prevDir = -1;
        redExist = false, blueExist = false;
    }

    Board(char board[10][10]) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                this->board[i][j] = board[i][j];
                if (board[i][j] == 'R') {
                    red[0] = j;
                    red[1] = i;
                } else if (board[i][j] == 'B') {
                    blue[0] = j;
                    blue[1] = i;
                } else if (board[i][j] == 'O') {
                    hole[0] = j;
                    hole[1] = i;
                }
            }
        }
        prevDir = -1;
        redExist = false, blueExist = false;
    }

public:

    void printBoard() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << this->board[i][j];
            }

            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    bool moveBall(int ball[2], int dir, int &moves) {
        static const int directions[4][2] = {
                {-1, 0},    // left
                {0,  1},     // bottom
                {1,  0},     // right
                {0,  -1}     // up
        };

        char whichBall = board[ball[1]][ball[0]];

        int *dt = const_cast<int *>(directions[dir]);
        if (dir == 0 || dir == 2) {  // horizontal
            int row = ball[1];
            int i = ball[0];
            while (i < m - 1 && i >= 1) {
                char ch = board[row][i + dt[0]];
                if (ch != '.') {
                    break;
                }
                i += dt[0];
            }

            if (board[row][i + dt[0]] == 'O') {
                board[row][ball[0]] = '.';
                moves += 1;
                return true;
            } else {
                board[row][ball[0]] = '.';
                board[row][i] = whichBall;
                moves += abs(i - ball[0]);
                ball[0] = i;
            }
        } else if (dir == 1 || dir == 3) {
            int col = ball[0];
            int i = ball[1];
            while (i < n - 1 && i >= 1) {
                char ch = board[i + dt[1]][col];
                if (ch != '.') {
                    break;
                }
                i += dt[1];
            }

            if (board[i + dt[1]][col] == 'O') {
                board[ball[1]][col] = '.';
                moves += 1;
                return true;
            } else {
                board[ball[1]][col] = '.';
                board[i][col] = whichBall;
                moves += abs(i - ball[1]);
                ball[1] = i;
            }
        }

        return false;
    }

    int tilt(int dir) {
        int ret = findFirstBall(dir);
        int moves = 0;
        if (ret == 0) {
            redExist = moveBall(red, dir, moves);
            blueExist = moveBall(blue, dir, moves);
        } else {
            blueExist = moveBall(blue, dir, moves);
            redExist = moveBall(red, dir, moves);
        }
        movesFromRoot++;
        setPrevDir(dir);

        return moves;
    }

    // 0 - red, blue, 1 - blue, red
    int findFirstBall(int dir) {
        if (dir == 0) {  // left
            return red[0] < blue[0] ? 0 : 1;
        } else if (dir == 2) {  // right
            return red[0] > blue[0] ? 0 : 1;
        } else if (dir == 1) {
            return red[1] > blue[1] ? 0 : 1;
        }

        return red[1] < blue[1] ? 0 : 1;
    }

    void setPrevDir(int dir) {
        prevDir = dir;
    }

    int getPrevDir() {
        return prevDir;
    }

    bool checkSuccess() {
        return redExist && !blueExist;
    }

    bool checkFail() {
        return blueExist;
    }

    int getMoves() {
        return movesFromRoot;
    }

private:
    char board[10][10];
    int red[2];     // y, x
    int blue[2];    // y, x
    int hole[2];
    int prevDir;
    bool redExist = false, blueExist = false;
    int movesFromRoot = 0;
};

int findShortestPath(int maxMoves, Board *root) {

    std::queue<Board *> neighbors;
    neighbors.push(root);

    int shortestPath = INT_MAX;
    while (!neighbors.empty()) {
        Board *neighbor = neighbors.front();
        neighbors.pop();
        if (neighbor->getMoves() >= maxMoves) {
            break;
        }

        for (int i = 0; i < 4; ++i) {
            if (neighbor->getPrevDir() == (i + 2) % 4) {
                continue;
            }

            Board *child = new Board(*neighbor);
            int moved = child->tilt(i);
            if (moved == 0) {
                continue;
            }

            if (!child->checkFail()) {
                if (child->checkSuccess()) {
                    shortestPath = std::min(shortestPath, child->getMoves());
                } else {
                    neighbors.push(child);
                }
            }
        }
    }

    return shortestPath == INT_MAX ? -1 : shortestPath;
}

int main() {
    std::cin >> n;
    std::cin >> m;

    char board[10][10];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> board[i][j];
        }
    }

    std::cout << findShortestPath(10, new Board(board)) << std::endl;
    return 0;
}

