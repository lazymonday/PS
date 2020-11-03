#include <bits/stdc++.h>

using namespace std;

const int ROUTE_MAX = 505;
const int CITY_MAX = 10005;
const int INF = 1e9;
typedef long long ll;

int root[CITY_MAX];
vector<int> route[ROUTE_MAX];

vector<pair<int, int>> routeA, routeB;

int uf_find(int p) {
    if (root[p] == -1) return p;
    return root[p] = uf_find(root[p]);
}

bool uf_merge(int p, int q) {
    p = uf_find(p);
    q = uf_find(q);

    if (p == q) return false;

    root[q] = p;
    return true;
}

int A, B, N;
int cost[ROUTE_MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> A >> B >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> cost[i];
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            int city;
            cin >> city;
            route[i].push_back(city);

            if (city == A) {
                routeA.push_back({i, j});
            } else if (city == B) {
                routeB.push_back({i, j});
            }
        }
    }

    int ans = INF;
    for (auto a : routeA) {
        for (auto b : routeB) {
            memset(root, -1, sizeof root);
            if (a.first == b.first && a.second > b.second) continue;
            for (int i = a.second + 1; i < route[a.first].size(); ++i)
            {
                uf_merge(A, route[a.first][i]);
            }

            for (int i = 0; i < b.second; ++i)
            {
                uf_merge(B, route[b.first][i]);
                if (uf_find(A) == uf_find(B)) {
                    int candidate = (a.first == b.first ? cost[a.first] : cost[a.first] + cost[b.first]);
                    ans = min(ans, candidate);
                }
            }

        }
    }

    cout << (ans == INF ? -1 : ans);

    return 0;
}
