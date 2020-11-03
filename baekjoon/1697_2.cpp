#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;

int solve(int e, int s) {
    if (e <= s) return s - e;
    else if (e == 1) return 1;
    else if (e % 2) return 1 + min(solve(e - 1, s), solve(e + 1, s));
    else return min(e - s, solve(e / 2, s));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int l, r;
    cin >> l >> r;
    cout << solve(r, l);
    return 0;
}
