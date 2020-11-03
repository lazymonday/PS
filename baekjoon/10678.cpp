#include <bits/stdc++.h>

using namespace std;

const int MAX = 18;
const int INF = 1e9;
typedef long long ll;

int N, M;
typedef vector<pair<int, int>> AdjList;
AdjList adjA[MAX];
AdjList adjB[MAX];

void dfs(int pos, bool isBessie, int total, vector<int>& ret) {
    if (pos == N) {
        ret.push_back(total);
        return;
    }

    auto& adj = (isBessie ? adjA[pos] : adjB[pos]);
    for (auto x : adj) {
        if (x.first == pos) continue;
        dfs(x.first, isBessie, total + x.second, ret);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        adjA[A].push_back({B, C});
        adjB[A].push_back({B, D});
    }

    vector<int> ret1, ret2;
    dfs(1, true, 0, ret1);
    dfs(1, false, 0, ret2);

    sort(ret1.begin(), ret1.end());
    sort(ret2.begin(), ret2.end());

    for (auto x : ret1)
    {
        for (auto xx : ret2) {
            if (x == xx) {
                cout << x;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
