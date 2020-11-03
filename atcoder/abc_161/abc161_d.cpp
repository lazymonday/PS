#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;

int k;

void solve(int kth) {
    queue<ll> q;
    for (int i = 1; i < 10; ++i)
    {
        q.push(i);
    }

    int index = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (++index == kth) {
            cout << cur;
            return;
        }

        ll last = cur % 10;
        for (int i = 0; i < 3; ++i)
        {
            ll offset = -1;
            if (last == 0) {
                offset = 0;
            }

            q.push(cur * 10ll + last + i + offset);
            if ((last == 9 || last == 0) && i == 1) break;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    solve(k);

    return 0;
}
