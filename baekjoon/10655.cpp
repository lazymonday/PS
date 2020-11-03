#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int x, y, px, py, ppx, ppy, psum1, psum2, psum3, distMax;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        if (i > 0) {
            psum3 = psum2 + abs(x - px) + abs(y - py);
            if (i > 1) {
                int dist = abs(x - ppx) + abs(y - ppy);
                if (psum3 - psum1 > dist) {
                    distMax = max(distMax, psum3 - psum1 - dist);
                }
            }
        }

        ppx = px, ppy = py;
        px = x, py = y;
        psum1 = psum2, psum2 = psum3;
    }


    cout << psum3 - distMax;

    return 0;
}
