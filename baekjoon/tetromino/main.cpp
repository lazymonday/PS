#include <iostream>
#include <algorithm>

struct Tetromino {
    int x[4];
    int y[4];

    Tetromino(int x[4], int y[4]) {
        for (int i = 0; i < 4; ++i) {
            this->x[i] = x[i];
            this->y[i] = y[i];
        }
    }
};

int n, m;

int findMaxSum();

// ㅡ
Tetromino tet_1[2] = {
        Tetromino(new int[4]{0, 1, 2, 3}, new int[4]{0, 0, 0, 0}),
        Tetromino(new int[4]{0, 0, 0, 0}, new int[4]{0, 1, 2, 3}),
};

// ㅁ
Tetromino tet_2[1] = {
        Tetromino(new int[4]{0, 1, 0, 1}, new int[4]{0, 0, 1, 1}),
};

// ㄴ
Tetromino tet_3[8] = {
        Tetromino(new int[4]{0, 0, 0, 1}, new int[4]{0, 1, 2, 2}),
        Tetromino(new int[4]{0, 1, 2, 0}, new int[4]{0, 0, 0, 1}),
        Tetromino(new int[4]{0, 1, 1, 1}, new int[4]{0, 0, 1, 2}),
        Tetromino(new int[4]{0, 1, 2, 2}, new int[4]{0, 0, 0, -1}),
        Tetromino(new int[4]{0, 0, 0, -1}, new int[4]{0, 1, 2, 2}),
        Tetromino(new int[4]{0, 0, 1, 2}, new int[4]{0, 1, 1, 1}),
        Tetromino(new int[4]{0, 0, 0, 1}, new int[4]{0, 1, 2, 0}),
        Tetromino(new int[4]{0, 1, 2, 2}, new int[4]{0, 0, 0, 1}),
};

// ㄱㄴ
Tetromino tet_4[4] = {
        Tetromino(new int[4]{0, 0, 1, 1}, new int[4]{0, 1, 1, 2}),
        Tetromino(new int[4]{0, 0, -1, -1}, new int[4]{0, 1, 1, 2}),
        Tetromino(new int[4]{0, 1, 1, 2}, new int[4]{0, 0, -1, -1}),
        Tetromino(new int[4]{0, 1, 1, 2}, new int[4]{0, 0, 1, 1}),
};

// ㅜ
Tetromino tet_5[4] = {
        Tetromino(new int[4]{0, 1, 2, 1}, new int[4]{0, 0, 0, -1}),  // ㅗ
        Tetromino(new int[4]{0, 1, 2, 1}, new int[4]{0, 0, 0, 1}),  // ㅜ
        Tetromino(new int[4]{0, 0, 0, 1}, new int[4]{0, 1, 2, 1}),  // ㅏ
        Tetromino(new int[4]{0, 0, 0, -1}, new int[4]{0, 1, 2, 1}),  // ㅓ
};
int board[502][502] = {0};

void printTetromino() {
    Tetromino *tets[] = {tet_1, tet_2, tet_3, tet_4, tet_5};
    int sizes[5] = {2, 1, 8, 4, 4};

    for (int k = 0; k < 5; ++k) {
        Tetromino *tet = tets[k];
        for (int i = 0; i < sizes[k]; ++i) {
            for (int j = 0; j < 4; ++j) {
                board[tet[i].y[j] + 1][tet[i].x[j] + 1] = 1;
            }

            for (int i = 0; i < 5; ++i) {    // row
                for (int j = 0; j < 5; ++j) {    // col
                    std::cout << board[i][j];
                    board[i][j] = 0;
                }
                std::cout << std::endl;
            }

            std::cout << std::endl;

        }
    }
}

int findMaxSum() {

    Tetromino *tets[] = {tet_1, tet_2, tet_3, tet_4, tet_5};
    int sizes[5] = {2, 1, 8, 4, 4};

    int max = 0;
    for (int k = 0; k < 5; ++k) {
        Tetromino *tet = tets[k];
        for (int i = 0; i < sizes[k]; ++i) {
            for (int r = 0; r < n + 2; ++r) {
                for (int c = 0; c < m + 2; ++c) {
                    int sum = 0;
                    for (int j = 0; j < 4; ++j) {
                        int x = tet[i].x[j] + c;
                        int y = tet[i].y[j] + r;

                        if (x < 0 || x > m + 1) {
                            break;
                        }
                        if (y < 0 || y > n + 1) {
                            break;
                        }

                        sum += board[y][x];
                    }

                    max = std::max(max, sum);
                }
            }

        }
    }

    return max;
}

int main() {

    //printTetromino();

    std::cin >> n;
    std::cin >> m;

    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {
                board[i][j] = 0;
            } else {
                std::cin >> board[i][j];
            }
        }
    }


    int ret = findMaxSum();
    std::cout << ret << std::endl;

    return 0;
}