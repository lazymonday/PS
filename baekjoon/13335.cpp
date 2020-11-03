#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int n, w, l;
int t[MAX + 1];
int pos[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> w >> l;

    for (int i = 0 ; i < n; ++i) {
        cin >> t[i];
    }

    queue<int> q;
    int tw = 0;
    int elapsed = 0;
    int idx = -1;

    while (true)
    {
        if (idx < n && tw + t[idx + 1] <= l) {
            ++idx;
            tw += t[idx];
            q.push(t[idx]);
            elapsed++;
        } else {
            q.push(0);
            elapsed++;
        }

        if (tw == 0) break;
        if (q.size() >= w) {
            tw -= q.front();
            q.pop();
        }
    }

    cout << elapsed;
    return 0;
}
