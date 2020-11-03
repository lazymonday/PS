#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int X, Y, M;

    cin >> X >> Y >> M;

    for (int m = M; m >= 0; --m) {

        for (int x = m / X; x >= 0; --x)
        {
            if (x * X == M) {
                cout << m;
                return 0;
            }

            int remain = m - (x * X);
            for (int y = remain / Y; y >= 0; --y)
            {
                if (y * Y == remain) {
                    cout << m;
                    return 0;
                }
            }
        }
    }

    return 0;
}
