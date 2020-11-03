#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4;
const int INF = 1e9;
typedef long long ll;

int n;
int tpos[MAX + 1];
int dist[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    char ch;
    int tsz = 0;
    int dsz = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> ch;
        if (ch == 'T') {
            cin >> tpos[tsz++];
        } else {
            cin >> dist[dsz++];
        }
    }

    sort(tpos, tpos + tsz);
    sort(dist, dist + dsz);

    int ti = 0;
    int di = 0;
    int vInv = 1;
    double traveled = 0;
    double takes = 0;
    double v = 1.0;
    while (traveled < 1000) {
        if (di < dsz || ti < tsz) {
            if (di >= dsz || (ti < tsz && (traveled + (tpos[ti] - takes) * v) < dist[di])) {
                traveled += (tpos[ti] - takes) * v;
                takes = tpos[ti++];
            } else {
                takes += (dist[di] - traveled) * vInv;
                traveled = dist[di++];
            }
            v = 1.0 / (double) ++vInv;
        } else {
            takes += (double)(1000 - traveled) * vInv;
            traveled = 1000;
        }
    }

    cout << (int)(takes + 0.5);

    return 0;
}
