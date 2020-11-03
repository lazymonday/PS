#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int n, m;
int a[MAX + 1][MAX + 1];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};


int bfs(pair<int, int> first, pair<int, int> second, pair<int, int>& target) {

    memset(a, 0, sizeof a);
    a[first.first][first.second] = 1;
    a[second.first][second.second] = 2;
    queue<pair<int, int>> q;

    q.push(first);
    q.push(second);

    int dist = 0;

    while (!q.empty()) {

        ++dist;
        for (int i = 0; i < q.size(); ++i) {
            auto r = q.front().first;
            auto c = q.front().second;

            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr <= 0 || nr > n || nc <= 0 || nc > n) continue;

                if (nr == target.first && nc == target.second) {
                    return
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    pair<int, int> first = {1, 1};
    pair<int, int> sec = {n, n};

    int tr, tc;
    while (m--) {
        cin >> tr >> tc;

        bfs(first, second, {tr, tc});
    }




    return 0;
}
