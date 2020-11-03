#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100;
const int INF = 2e9;
typedef long long ll;

int row, col;
int a[MAX + 1][MAX + 1];
int visited[MAX + 1][MAX + 1];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

int dfs(int r, int c) {
    if (visited[r][c]) return 0;
    visited[r][c] = true;

    if (a[r][c] == 1) {
        a[r][c] = 0;
        return 1;
    }

    int ret = 0;
    for (int i = 0; i < 4; ++i)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
            continue;
        }

        if (!visited[nr][nc]) {
            ret += dfs(nr, nc);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> row >> col;
    int ones = 0;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cin >> a[i][j];
            if (a[i][j]) ones++;
        }
    }

    int hours = 0;
    while (ones > 0) {
        int ret = dfs(0, 0);
        if (ret == 0) {
            break;
        }

        ones = ret;
        hours++;
        memset(visited, 0, sizeof visited);
    }

    cout << hours << "\n" << ones << "\n";

    return 0;
}
