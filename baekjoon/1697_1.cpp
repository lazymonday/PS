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
int parent[MAX + 1];

int solve(int start) {

    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int n1[] = {1, 1, 2};
    int n2[] = {1, -1, 0};

    while (!q.empty()) {
        auto here = q.front();
        q.pop();

        if (visited[here]) continue;

        if (here == k) {
            return dist[here];
        }

        visited[here] = true;
        for (int i = 0; i < 3; ++i)
        {
            int next = here * n1[i] + n2[i];
            if (next < 0 || next > MAX || visited[next]) continue;
            int dt = 1;
            if (dist[next] > dist[here] + dt) {
                q.push(next);
                dist[next] = dist[here] + dt;
                parent[next] = here;
            }

        }
    }

    return INF;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(parent, -1, sizeof parent);
    for (int i = 0; i <= MAX; ++i)
        dist[i] = INF;


    cin >> n >> k;
    int ret = solve(n);
    cout << ret << "\n";
    vector<int> v;
    for (int p = k; p != -1; p = parent[p])
        v.push_back(p);

    reverse(v.begin(), v.end());
    for (auto x : v) {
        cout << x << " ";
    }

    return 0;
}
