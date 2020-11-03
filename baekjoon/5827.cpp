#include <bits/stdc++.h>

using namespace std;

const int MAX = 500;
const int INF = 1e9;
typedef long long ll;

int row, col;
char grid[MAX + 1][MAX + 1];
int dist[MAX + 1][MAX + 1];
pair<int, int> start, goal;

int getDir(bool flipped) {
    return flipped ? -1 : 1;
}

pair<int, int> fall(const pair<int, int>& here, int dir) {
    pair<int, int> next(here);
    while (true) {
        if (grid[next.first][next.second] == 'D') break;
        if (next.first + dir < 0 || next.first + dir >= row) {
            return { -1, -1};
        }
        if (grid[next.first + dir][next.second] == '#') break;

        next.first += dir;
    }

    return next;
}

pair<int, int> move_cb(const pair<int, int>& here, int cmd, int dir) {

    if (cmd != 0) {
        int nc = here.second + cmd;
        if (nc < 0 || nc >= col || grid[here.first][nc] == '#') return { -1, -1};

        return fall({here.first, nc}, dir);
    }

    return fall(here, -dir);
}

void solve(pair<int, int> s) {

    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<int, pair<int, int>>> pq;

    dist[s.first][s.second] = 1;
    pq.push({ -1, s});

    while (!pq.empty()) {

        auto& top = pq.top();
        int cost = -top.first;
        auto here = top.second;

        if (here == goal) break;

        pq.pop();
        if (dist[here.first][here.second] < cost) continue;

        for (int i = -1; i <= 1; ++i) {
            auto next = move_cb(here, i, (dist[here.first][here.second] % 2 ? 1 : -1));
            if (next.first != -1 && dist[next.first][next.second] == 0x3f3f3f3f) {
                dist[next.first][next.second] = dist[here.first][here.second];
                if (i == 0) {
                    dist[next.first][next.second]++;
                }

                pq.push({ -dist[next.first][next.second], next});
            }
        }
    }
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
            if (grid[i][j] == 'C') {
                start = {i, j};
            } else if (grid[i][j] == 'D') {
                goal = {i, j};
            }
        }
    }

    start = fall(start, 1);
    if (start.first >= 0) {
        solve(start);
    }

    int ans = dist[goal.first][goal.second];
    cout << (ans == 0x3f3f3f3f ? -1 : ans - 1);
    return 0;
}
