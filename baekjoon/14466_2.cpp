#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int n, k, r;
int farm[MAX + 1][MAX + 1][4];
pair<int, int> cows[MAX + 1];
int root[(MAX + 1) * (MAX + 1)];

int disj_find(int p) {
    if (root[p] < 0) return p;
    return root[p] = disj_find(root[p]);
}

bool disj_union(int p, int q) {
    p = disj_find(p);
    q = disj_find(q);
    if (p == q) return false;

    root[q] = p;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(root, -1, sizeof root);
    cin >> n >> k >> r;

    int r1, c1, r2, c2;
    for (int i = 0; i < r; ++i)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        for (int d = 0; d < 4; ++d) {
            int rr = r1 + dr[d];
            int cc = c1 + dc[d];
            if (rr == r2 && cc == c2) {
                farm[r2][c2][(d + 2) % 4] = farm[r1][c1][d] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < k; ++i)
    {
        cin >> cows[i].first >> cows[i].second;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int d = 0; d < 4; ++d)
            {
                if (farm[i][j][d]) continue;
                int nr = i + dr[d];
                int nc = j + dc[d];

                if (nr < 1 || nr > n || nc < 1 || nc > n) continue;
                disj_union(i * n + j, nr * n + nc);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        for (int j = i + 1; j < k; ++j)
        {
            if (disj_find(cows[i].first * n + cows[i].second) != disj_find(cows[j].first * n + cows[j].second)) {
                ++ans;
            }
        }
    }

    cout << ans;
    return 0;
}
