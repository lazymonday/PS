#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 500;
int dp[MAX + 1][MAX + 1];
short road[MAX + 1][MAX + 1];
short dc[] = {1, -1, 0, 0};
short dr[] = {0, 0, 1, -1};
short row, col;

int solve(short r, short c) {

    if (r == row && c == col) {
        return 1;
    }

    auto &ret = dp[r][c];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (int i = 0; i < 4; ++i) {
        int nr = dr[i] + r;
        int nc = dc[i] + c;
        if (nr <= 0 || nr > row || nc <= 0 || nc > col) {
            continue;
        }

        if (road[r][c] > road[nr][nc]) {
            ret += solve(nr, nc);
        }
    }

    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> row >> col;
    for (int r = 1; r <= row; ++r) {
        for (int c = 1; c <= col; ++c) {
            cin >> road[r][c];
        }
    }

    memset(dp, -1, sizeof dp);
    cout << solve(1, 1);
    return 0;
}
