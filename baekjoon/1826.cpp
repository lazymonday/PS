#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1e4;
const int INF = 2e9;
typedef long long ll;

int n;
pair<int, int> oil[MAX + 1];
int L, fuel;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &oil[i].first, &oil[i].second);
    scanf("%d%d", &L, &fuel);

    oil[n].first = L;
    oil[n].second = 0;

    sort(oil, oil + n + 1, [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    int ans = 0;
    priority_queue<int> pq;
    for (int i = 0; i <= n; ++i)
    {
        while (oil[i].first > fuel) {
            if (pq.empty()) {
                printf("-1");
                return 0;
            }

            fuel += pq.top();
            pq.pop();
            ans++;
        }

        if (oil[i].second >= L) {
            break;
        }
        pq.push(oil[i].second);
    }

    printf("%d", ans);
    return 0;
}
