#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e2;
const int INF = 1e9;
typedef long long ll;

int n;
int a[MAX + 5];
int bPos[MAX + 5];
int seen[MAX + 5];

int check_cycle(int start) {
    int cnt = 1;
    int next = bPos[a[start]];

    while (next != start) {
        seen[next] = 1;
        next = bPos[a[next]];
        cnt++;
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int b;
    for (int i = 0; i < n; ++i)
    {
        cin >> b;
        bPos[b] = i;
    }

    int cycle_cnt = 0, cycle_len = -1;
    for (int i = 0; i < n; ++i)
    {
        if (seen[i] || i == bPos[a[i]]) continue;
        int cnt = check_cycle(i);
        cycle_cnt++;
        cycle_len = max(cycle_len, cnt);
    }

    cout << cycle_cnt << " " << cycle_len;

    return 0;
}
