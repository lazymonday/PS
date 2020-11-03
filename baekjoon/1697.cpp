#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 2e5;
const int INF = 2e9;
typedef long long ll;

int n, k;
bool visited[200000];

int solve(int start) {

    queue<pair<int, int>> q;
    q.push({start, 0});

    int n1[] = {1, 1, 2};
    int n2[] = {1, -1, 0};

    while (!q.empty()) {
        auto x = q.front();
        q.pop();

        if (x.first == k) {
            return x.second;
        }

        visited[x.first] = true;
        for (int i = 0; i < 3; ++i)
        {
            int next = x.first * n1[i] + n2[i];
            if (next < 0 || visited[next]) continue;
            q.push({next, x.second + 1});
        }

    }

    return INF;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    cout << solve(n);
    return 0;
}
