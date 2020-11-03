#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
const int INF = 1e9;
typedef long long ll;

int psum[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, S;
    cin >> N >> S;

    for (int i = 1; i <= N; ++i)
    {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }

    int ans = INF;
    int pos = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (psum[i] < S) continue;
        while (pos + 1 < N && i > pos + 1 && psum[i] - psum[pos + 1] >= S) pos++;
        ans = min(ans, i - pos);
    }

    cout << (ans == INF ? 0 : ans);

    return 0;
}
