#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1e3;
const int INF = 2e9;
typedef long long ll;

int n, k;
pair<int, int> a[MAX + 2];
bool visited[MAX + 2];

inline int getLength(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool bfs(int fuel) {

    const int maxDist = fuel * fuel * 100;
    memset(visited, false, sizeof visited);
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0] = true;
    while (!q.empty()) {
        auto here = q.front().first;
        auto stop = q.front().second;
        q.pop();

        for (int i = 1; i <= n; ++i)
        {
            if (visited[i]) continue;
            if (getLength(a[here].first, a[here].second, a[i].first, a[i].second) <= maxDist) {
                visited[i] = true;
                q.push({i, stop + 1});

                if (a[i].first == 10000 && a[i].second == 10000) {
                    return stop <= k;
                }
            }
        }
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].first, &a[i].second);

    n++;
    a[n].first = a[n].second = 10000;
    a[0].first = a[0].second = 0;

    int lo = 0;
    int hi = 1500;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (!bfs(mid)) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    printf("%d", lo);

    return 0;
}
