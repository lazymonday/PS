#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
const int INF = 1e9;
typedef long long ll;

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

int n, k, r;

typedef pair<int, int> pii;

vector<pii> w[MAX + 1][MAX + 1];
pii cow[MAX + 1];

int dist[MAX + 1][MAX + 1];

void dijkstra(int r, int c) {

    memset(dist, 0x3f, sizeof dist);

    priority_queue<pair<int, pii>> pq;
    dist[r][c] = 0;
    pq.push({0, {r, c}});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        pii here = pq.top().second;
        pq.pop();

        if (dist[here.first][here.second] < cost) continue;

        for (int i = 0 ; i < 4; ++i) {
            int nr = here.first + dr[i];
            int nc = here.second + dc[i];

            if (nr < 1 || nr > n || nc < 1 || nc > n) continue;

            bool isRoad = false;
            for (auto e : w[here.first][here.second]) {
                if (e.first == nr && e.second == nc) {
                    isRoad = true;
                    break;
                }
            }

            int nextCost = cost + (isRoad ? 1 : 0);
            if (nextCost < dist[nr][nc]) {
                dist[nr][nc] = nextCost;
                pq.push({ -nextCost, {nr, nc}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> r;
    int a, b, c, d;
    for (int i = 0; i < r; ++i)
    {
        cin >> a >> b >> c >> d;
        w[a][b].push_back({c, d});
        w[c][d].push_back({a, b});
    }

    for (int i = 1; i <= k; ++i)
    {
        cin >> cow[i].first >> cow[i].second;
    }

    int ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        dijkstra(cow[i].first, cow[i].second);
        for (int j = i + 1; j <= k; ++j)
        {
            int distant = dist[cow[j].first][cow[j].second];
            if (distant > 0 && distant != 0x3f3f3f3f) {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
