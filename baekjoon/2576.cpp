#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    int maxn = INF;
    for (int i = 0; i < 7; ++i)
    {
        int k;
        cin >> k;
        if (k % 2 == 1) {
            sum += k;
            maxn = min(maxn, k);
        }
    }

    if(maxn == INF) {
        cout << -1;
        return 0;
    }

    cout << sum << "\n" << maxn;



    return 0;
}
