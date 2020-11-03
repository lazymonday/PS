#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAX = 100;
int n;

int geo[MAX][MAX];
int visited[MAX][MAX];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};


void dfs(int r, int c, int rainfall) {
    visited[r][c] = 1;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < 0 || nr > n || nc < 0 || nc > n || visited[nr][nc] || geo[nr][nc] <= rainfall) {
            continue;
        }

        dfs(nr, nc, rainfall);
    }
}

int main() {
    cin >> n;

    int upper = -INF;
    int lower = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> geo[i][j];
            upper = max(upper, geo[i][j]);
            lower = min(lower, geo[i][j]);
        }
    }

    int maxArea = -INF;
    for (int rainfall = max(lower - 1, 0); rainfall <= upper; ++rainfall) {
        int areaCount = 0;
        memset(visited, 0, sizeof visited);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (!visited[r][c] && geo[r][c] > rainfall) {
                    dfs(r, c, rainfall);
                    ++areaCount;
                }
            }
        }

        maxArea = max(maxArea, areaCount);
    }

    cout << maxArea << endl;

    return 0;
}

