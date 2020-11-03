#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e3;
const int MAX_COL = 2e3;
const int INF = 1e9;
typedef long long ll;

int n;
string a;

int adj[MAX * MAX + 5];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};

bool seen[MAX * MAX + 5];
bool finished[MAX * MAX + 5];

int index(int r, int c) {
    return r * MAX_COL + c;
}

int getDir(char ch) {
    switch (ch) {
    case 'N':
        return 0;
    case 'W':
        return 1;
    case 'S':
        return 2;
    case 'E':
        return 3;
    }

    return -1;
}

int dfs(int u, int from) {
    int ret = 0;
    seen[u] = true;

    int r = u / MAX_COL;
    int c = u % MAX_COL;

    for (int i = 0; i < 4; ++i) {
        if ((adj[u] & (1 << i)) == 0) continue;
        int next = index(r + dr[i], c + dc[i]);
        if (seen[next]) {
            if (!finished[next] && next != from) ret++;
            continue;
        }

        ret += dfs(next, u);
    }

    finished[u] = true;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a;

    int r = 1000, c = 1000;
    for (int i = 0; i < n; ++i)
    {
        int dir = getDir(a[i]);
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        adj[index(r, c)] |= (1 << dir);
        adj[index(nr, nc)] |= (1 << ((dir + 2) % 4));
        r = nr, c = nc;
    }

    cout << dfs(index(1000, 1000), -1);

    return 0;
}