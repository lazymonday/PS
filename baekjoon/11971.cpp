#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;
const int INF = 1e9;
typedef long long ll;

int N, M;
int limit[MAX];
int speed[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int start = 0, a, b;
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        for (int j = start + 1; j <= start + a; ++j)
            limit[j] = b;
        start += a;
    }

    start = 0;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        for (int j = start + 1; j <= start + a; ++j)
            speed[j] = b;
        start += a;
    }


    int ans = 0;
    for (int i = 1; i <= 100; ++i)
    {
        if (speed[i] <= limit[i]) continue;
        ans = max(ans, speed[i] - limit[i]);
    }

    cout << ans;

    return 0;
}
