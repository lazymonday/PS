#include <bits/stdc++.h>

using namespace std;

const int MAX = 200;
const int INF = 1e9;
typedef long long ll;

int R, C, N;

int grid[MAX + 1][MAX + 1];
int tmp[MAX + 1][MAX + 1];
int dr[] = {0, 0, -1, 1};
int dc[] = { -1, 1, 0, 0};

void elapse(int curr) {

    memcpy(tmp, grid, sizeof grid);
    if (curr % 2) {
        // explode bombs
        for (int r = 0; r < R; ++r)
        {
            for (int c = 0; c < C; ++c)
            {
                if (tmp[r][c] != -1 && curr - tmp[r][c] >= 3) {

                    grid[r][c] = -1;
                    for (int i = 0; i < 4; ++i)
                    {
                        int nr = r + dr[i];
                        int nc = c + dc[i];

                        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                        grid[nr][nc] = -1;
                    }

                }
            }
        }
    } else {
        // fill bombs
        for (int r = 0; r < R; ++r)
        {
            for (int c = 0; c < C; ++c)
            {
                if (grid[r][c] == -1) {
                    grid[r][c] = curr;
                }
            }
        }
    }
}

void printField() {
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cout << (grid[i][j] == -1 ? '.' : 'O');
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> N;

    memset(grid, -1, sizeof grid);

    char ch;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> ch;
            if (ch == 'O') {
                grid[i][j] = 0;
            }
        }
    }

    if (N > 4) {
        N = (N - 3) % 4 + 3;
        if (N % 2 == 0) {
            N = 2;
        } else if (N % 4 == 1) {
            N = 5;
        } else if ( N % 4 == 3) {
            N = 3;
        }
    }

    for (int t = 2; t <= N; ++t) {
        printField();
        elapse(t);
    }

    printField();
    return 0;
}
