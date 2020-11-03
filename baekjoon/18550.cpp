#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
const int INF = 1e9;
typedef long long ll;

int mineral[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];

int R, C;
int throws;
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

typedef vector<pair<int, int>> Cluster;

bool dfs(int r, int c, Cluster& out) {

    visited[r][c] = true;
    out.push_back({r, c});

    if (r == R) return true;

    for (int i = 0; i < 4; ++i)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 1 || nr > R || nc < 1 || nc > C
                || visited[nr][nc] || mineral[nr][nc] == 0) continue;


        if (dfs(nr, nc, out)) return true;
    }

    return false;
}

void down_cluster(Cluster& cluster) {

    bool stucked = false;
    while (!stucked) {
        Cluster tmp(cluster);
        for (int i = 0; i < tmp.size(); ++i)
        {
            int nr = tmp[i].first + 1;
            int nc = tmp[i].second;

            if (nr > R || mineral[nr][nc] == 1) {
                stucked = true;
                break;
            } else {
                tmp[i].first = nr;
            }
        }

        if (!stucked) {
            cluster = tmp;
        }
    }
}

void set_cluster(bool isSet, const Cluster& cluster) {
    for (int i = 0; i < cluster.size(); ++i)
    {
        int r = cluster[i].first;
        int c = cluster[i].second;
        mineral[r][c] = (isSet ? 1 : 0);
    }
}

void print_mineral() {
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            cout << (mineral[i][j] ? 'x' : '.');
        }
        cout << "\n";
    }
}

void stick(int h, bool fromLeft) {

    int col = -1;
    if (fromLeft) {
        for (int i = 1; i <= C; ++i)
            if (mineral[h][i]) {
                col = i;
                break;
            }
    } else {
        for (int i = C; i >= 1; --i)
            if (mineral[h][i]) {
                col = i;
                break;
            }
    }

    if (col != -1) {
        mineral[h][col] = 0;
        for (int i = 0; i < 4; ++i)
        {
            memset(visited, 0, sizeof visited);
            int nr = h + dr[i];
            int nc = col + dc[i];

            if (nr < 1 || nr > R || nc < 1 || nc > C || mineral[nr][nc] == 0) continue;
            Cluster cl;
            if (!dfs(nr, nc, cl)) {
                set_cluster(false, cl);
                down_cluster(cl);
                set_cluster(true, cl);
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 1; i <= R; ++i)
    {
        char ch;
        for (int j = 1; j <= C; ++j)
        {
            cin >> ch;
            mineral[i][j] = (ch == '.' ? 0 : 1);
        }
    }

    cin >> throws;
    for (int i = 1; i <= throws; ++i)
    {
        int h;
        cin >> h;
        h = R - h + 1;
        stick(h, ((i % 2) == 1));
    }

    print_mineral();

    return 0;
}
