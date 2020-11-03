#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;
const int INF = 1e9;
typedef long long ll;

int n;
char field[21][21];
int visited[21][21];
int dr[] = {0, 0, -1, 1};
int dc[] = { -1, 1, 0, 0};

struct PCL {
    int lr, lc, rr, rc; // left top, right bottom

    inline bool inRange(int r, int c) const {
        return (lr <= r && r <= rr && lc <= c && c <= rc);
    }

    inline bool isInclude(const PCL& other) const {
        return inRange(other.lr, other.lc) && inRange(other.rr, other.rc);
    }
};

void dfs(const PCL& pcl, int r, int c) {
    visited[r][c] = true;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (visited[nr][nc] || !pcl.inRange(nr, nc)) continue;

        if (field[nr][nc] == field[r][c]) {
            dfs(pcl, nr, nc);
        }
    }
}

bool isValid(const PCL& pcl) {

    int cnt[26] = {0, };
    memset(visited, 0, sizeof visited);

    for (int r = pcl.lr; r <= pcl.rr; ++r)
    {
        for (int c = pcl.lc; c <= pcl.rc; ++c)
        {
            if (visited[r][c]) continue;
            dfs(pcl, r, c);
            cnt[field[r][c] - 'A']++;
        }
    }

    int count = 0;
    bool one = false, many = false;
    for (int i = 0; i < 26 && count <= 2; ++i)
    {
        if (cnt[i]) {
            count++;
            if (cnt[i] == 1) one = true;
            if (cnt[i] > 1) many = true;
        }
    }

    if (count == 2 && one && many) {
        return true;
    }

    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int z = 0; z < n; ++z)
        for (int zz = 0; zz < n; ++zz)
            cin >> field[z][zz];

    vector<PCL> candidates;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = i; k < n; ++k)
                for (int l = j; l < n; ++l) {
                    PCL pcl({i, j, k, l});
                    if (isValid(pcl)) {
                        candidates.emplace_back(pcl);
                    }
                }


    int ans = 0;
    for (int i = 0; i < candidates.size(); ++i)
    {
        bool valid = true;
        for (int j = 0; j < candidates.size(); ++j)
        {
            if (i == j) continue;
            if (candidates[j].isInclude(candidates[i])) {
                valid = false;
                break;
            }
        }

        if (valid) ans++;
    }

    cout << ans;
    return 0;
}