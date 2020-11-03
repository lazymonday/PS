#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;
const int INF = 1e9;
typedef long long ll;


int row, col;

char grid[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];
int tdist[MAX + 1][MAX + 1];
bool calculated[16];
bool taken[16];
int dist[16][16];
int dp[16][1 << 16];

int dr[] = {0, 0, -1, 1};
int dc[] = { -1, 1, 0, 0};

void bfs(int r, int c, int start) {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {r, c}});
    visited[r][c] = true;
    memset(tdist, 0x3f, sizeof tdist);
    tdist[r][c] = 0;

    while (!q.empty()) {

        int distance = q.front().first;
        r = q.front().second.first;
        c = q.front().second.second;

        q.pop();

        int group = grid[r][c];
        if (group < 15) {
            dist[start][group] = min(dist[start][group], tdist[r][c]);
        }

        for (int j = 0; j < 4; ++j)
        {
            int nr = r + dr[j];
            int nc = c + dc[j];

            int next = grid[nr][nc];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || next == '.') {
                continue;
            }

            if (next == 'S') {
                if (tdist[nr][nc] > distance + 1) {
                    q.push({distance + 1, {nr, nc}});
                    tdist[nr][nc] = distance + 1;
                }

            } else {
                if (tdist[nr][nc] > distance) {
                    q.push({distance, {nr, nc}});
                    tdist[nr][nc] = distance;
                }
            }
        }
    }
}

void calcDist(int towns) {

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            int color = grid[i][j];
            if (color < 15) {
                if (calculated[color]) continue;
                memset(visited, false, sizeof visited);
                bfs(i, j, color);
                calculated[color] = true;
            }
        }
    }
}

void dfs(int r, int c, int color) {

    if (visited[r][c]) return;

    visited[r][c] = true;
    grid[r][c] = color;

    for (int i = 0; i < 4; ++i)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= row || nc < 0 || nc >= col || grid[nr][nc] != 'X') continue;

        dfs(nr, nc, color);
    }
}

int floodfill() {

    memset(visited, 0, sizeof visited);
    int color = 0;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (grid[i][j] != 'X') continue;
            dfs(i, j, color++);
        }
    }

    return color;
}


int tsp(int towns, int here, int chosen) {

    //chosen |= (1 << here);
    if (chosen == (1 << towns) - 1) {
        return 0;
    }

    auto& ret = dp[here][chosen];
    if (ret != -1) {
        return ret;
    }

    ret = INF;
    for (int i = 0; i < towns; ++i)
    {
        if (chosen & (1 << i)) continue;
        int cand = tsp(towns, i, chosen | (1 << i));
        cand += dist[here][i];
        ret = min(ret, cand);

    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> row >> col;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cin >> grid[i][j];
        }
    }

    memset(dist, 0x3f, sizeof dist);
    int towns = floodfill();
    calcDist(towns);

    int ans = INF;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < towns; ++i)
    {
        ans = min(ans, tsp(towns, i, 1 << i));
    }

    cout << ans;

    return 0;
}
