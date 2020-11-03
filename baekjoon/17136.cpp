#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

const int n = 10;
int a[10][10];
int remain[6] = {0, 5, 5, 5, 5, 5};
int ans = INF;

int setVal(int row, int col, int width, int value) {
    if (value == 2) remain[width]--;
    else if (value == 1) remain[width]++;

    for (int r = row; r < row + width; ++r)
        for (int c = col; c < col + width; ++c)
            a[r][c] = value;

    return width * width;
}

bool chk(int row, int col, int width) {
    int bottom = row + width;
    int right = col + width;

    if (remain[width] <= 0 || right > n || bottom > n) return false;

    for (int r = row; r < bottom; ++r)
        for (int c = col; c < right; ++c)
            if (a[r][c] != 1) return false;

    return true;
}

void solve(int row, int col, int cnt, int sum) {

    if (sum == 0) {
        ans = min(ans, cnt);
        return;
    }

    for (int r = row; r < n; ++r) {
        int c = 0;
        if (r == row) c = col;
        for ( ; c < n; ++c) {
            if (a[r][c] == 1) {
                for (int i = 1; i <= 5; ++i) {
                    if (!chk(r, c, i)) continue;
                    solve(r, c, cnt + 1, sum - setVal(r, c, i, 2));
                    setVal(r, c, i, 1);
                }
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int total = 0;
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < n; ++c) {
            cin >> a[r][c];
            if (a[r][c]) total++;
        }

    solve(0, 0, 0, total);
    cout << (ans == INF ? -1 : ans);

    return 0;
}
