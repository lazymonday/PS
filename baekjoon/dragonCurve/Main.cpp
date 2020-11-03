#include <iostream>
#include <algorithm>

int boardMax = 101;
int **dragonBoard = new int *[boardMax];

void setPoint(int **board, int x, int y) {
    board[y][x] = 1;
}

void moveToDir(int *x, int *y, int dir) {
    if (dir == 0) {
        (*x)++;
    } else if (dir == 2) {
        (*x)--;
    } else if (dir == 1) {
        (*y)--;
    } else if (dir == 3) {
        (*y)++;
    }
}

int nextGen(int *board, int n, int current, int x, int y, int d, int g) {
    if (g < 0) {
        return current;
    }

    for (int i = current - 1; i >= 0; --i) {
        int dir = (board[i] + 1) % 4;
        board[current++] = dir;
        moveToDir(&x, &y, dir);
        setPoint(dragonBoard, x, y);
    }

    return nextGen(board, n, current, x, y, board[current - 1], g - 1);
}

int countAllSquare() {

    int countOfAllPointOccupied = 0;
    for (int i = 0; i < boardMax - 1; ++i) {
        for (int j = 0; j < boardMax - 1; ++j) {
            if (dragonBoard[i][j] == 1 &&
                dragonBoard[i + 1][j] == 1 &&
                dragonBoard[i][j + 1] == 1 &&
                dragonBoard[i + 1][j + 1] == 1) {
                countOfAllPointOccupied++;
            }
        }
    }

    return countOfAllPointOccupied;
}

int main() {

    for (int i = 0; i < boardMax; ++i) {
        dragonBoard[i] = new int[boardMax];
        for (int j = 0; j < boardMax; ++j) {
            dragonBoard[i][j] = 0;
        }
    }

    int cases = 0;
    std::cin >> cases;

    int x, y, d, g;

    while (--cases >= 0) {
        std::cin >> x;
        std::cin >> y;
        std::cin >> d;
        std::cin >> g;

        int *board = new int[boardMax * boardMax];
        board[0] = d;
        setPoint(dragonBoard, x, y);
        moveToDir(&x, &y, d);
        setPoint(dragonBoard, x, y);

        nextGen(board, boardMax, 1, x, y, d, g - 1);
    }

    std::cout << countAllSquare() << std::endl;


    return 0;
}
