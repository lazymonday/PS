#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;
const int INF = 1e9;
typedef long long ll;

int ROW, COL;
int a[MAX][MAX];
int b[MAX][MAX];
int seen[MAX][MAX];
int ans[MAX][MAX];
int dr[] = {0, 0, 1, -1, 0};
int dc[] = {1, -1, 0, 0, 0};

int flip(int r, int c) {
    seen[r][c]++;
    int dt = 0;
    for (int i = 0; i < 5; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL) continue;

        dt += (b[nr][nc] ? -1 : 1);
        b[nr][nc] ^= 1;
    }

    return dt;
}

bool solve(int topState, int tiles, int& outFlipCnt) {
    for (int i = 0; i < COL; ++i) {
        if ((1 << i) & topState) {
            tiles += flip(0, COL - i - 1);
            outFlipCnt++;
        }
    }

    for (int r = 1; r < ROW; ++r) {
        for (int c = 0; c < COL; ++c) {
            if (b[r - 1][c]) {
                tiles += flip(r, c);
                outFlipCnt++;
            }
        }
    }

    return tiles == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int total = 0;
    cin >> ROW >> COL;
    for (int r = 0; r < ROW; ++r)
    {
        for (int c = 0; c < COL; ++c)
        {
            cin >> a[r][c];
            if (a[r][c]) total++;
        }
    }

    int upper = 1 << COL;
    int minVal = INF;
    for (int x = 0; x < upper; ++x) {

        memcpy(b, a, sizeof a);
        memset(seen, 0, sizeof seen);

        int cnt = 0;
        if (solve(x, total, cnt)) {
            if (minVal > cnt) {
                minVal = cnt;
                memcpy(ans, seen, sizeof seen);
            }
        }
    }

    if (minVal == INF) {
        cout << "IMPOSSIBLE";
    } else {
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j)
                cout << ans[i][j] << (j == COL - 1 ? "\n" : " ");
        }
    }

    return 0;
}
