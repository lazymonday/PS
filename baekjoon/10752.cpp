#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;
const int INF = 15;
typedef long long ll;

int R, C;
int grid[MAX + 1][MAX + 1];

int search(int sr, int sc) {

    if (sr == R - 1 && sc == C - 1) {
        return 1;
    }

    int ret = 0;
    for (int i = sr + 1; i < R; ++i)
    {
        for (int j = sc + 1; j < C; ++j)
        {
            if (grid[sr][sc] != grid[i][j]) {
                ret += search(i, j);
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char ch;
    cin >> R >> C;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> ch;
            if (ch == 'B') grid[i][j] = 1;
        }
    }

    cout << search(0, 0);

    return 0;
}
