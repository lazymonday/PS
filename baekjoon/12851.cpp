#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;

int n, k;
bool visited[MAX + 1];
int dist[MAX + 1];
int cnt[MAX + 1];

void solve(int start) {

    queue<int> q;
    q.push(start);
    dist[start] = 0;
    cnt[start] = 1;

    int n1[] = {1, 1, 2};
    int n2[] = {1, -1, 0};

    while (!q.empty()) {
        auto here = q.front();
        q.pop();

        if (visited[here]) continue;

        if (here == k) {
            continue;
        }

        visited[here] = true;
        for (int i = 0; i < 3; ++i)
        {
            int next = here * n1[i] + n2[i];
            if (next < 0 || next > MAX || visited[next]) continue;
            if (dist[next] > dist[here] + 1) {
                q.push(next);
                dist[next] = dist[here] + 1;
                cnt[next] += cnt[here];
            } else if(dist[next] >= dist[here] + 1){
                cnt[next] += cnt[here];
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i <= MAX; ++i)
        dist[i] = INF;

    cin >> n >> k;
    solve(n);
    cout << dist[k] << "\n";
    cout << cnt[k] << "\n";
    return 0;
}
