#include <iostream>

using namespace std;

int room[50][50];

int row, col, t;
int filter_head[2]; // r, c
int filter_tail[2]; // r, c

int dir_c[] = {1, -1, 0, 0};    // right(0), left(1), down(2), up(3)
int dir_r[] = {0, 0, 1, -1};

int cw[] = {2, 0, 3, 1};    // down, right, up, left
int ccw[] = {3, 0, 2, 1};   // up, right, down, left

int countDust() {
    int totalDust = 0;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (room[r][c] > 0) {
                totalDust += room[r][c];
            }
        }
    }

    return totalDust;
}

void spread() {
    int room_tmp[50][50] = {0};

    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (room[r][c] > 0) {
                int val = room[r][c] / 5;
                for (int k = 0; k < 4; ++k) {
                    int cc = c + dir_c[k];
                    int rr = r + dir_r[k];

                    if (rr < 0 || rr >= row || cc < 0 || cc >= col) {
                        continue;
                    }

                    if (room[rr][cc] == -1) {
                        continue;
                    }

                    room[r][c] -= val;
                    room_tmp[rr][cc] += val;
                }
            }
        }
    }

    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            room[r][c] += room_tmp[r][c];
        }
    }
}

int forwardRow(int r, int dir, bool isCW) {
    return r + dir_r[isCW ? cw[dir] : ccw[dir]];
}

int forwardCol(int c, int dir, bool isCW) {
    return c + dir_c[isCW ? cw[dir] : ccw[dir]];
}

void filter(int start[2], bool isCW) {
    int dir = 0;
    int r = start[0];
    int c = start[1];

    while (dir < 4) {
        int nr = forwardRow(r, dir, isCW);
        int nc = forwardCol(c, dir, isCW);

        if (nr < (!isCW ? 0 : start[0]) || nr >= (!isCW ? start[0] + 1 : row) || nc < 0 || nc >= col) {
            ++dir;
            continue;
        }

        if (room[r][c] != -1) {
            room[r][c] = room[nr][nc];
        }

        r = nr;
        c = nc;
    }

    room[r][c + 1] = 0;
}


int main() {

    cin >> row >> col >> t;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            cin >> room[r][c];
            if (room[r][c] == -1) {
                filter_head[0] = r - 1;
                filter_head[1] = c;
                filter_tail[0] = r;
                filter_tail[1] = c;
            }
        }
    }

    while (--t >= 0) {
        spread();
        filter(filter_head, false);
        filter(filter_tail, true);
    }

    cout << countDust() << endl;

    return 0;
}
