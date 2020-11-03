#include <iostream>

using namespace std;
typedef long long ll;
const int MAX = 1e5;
ll dp[MAX + 1];
int height[MAX + 1];
int la[MAX + 1];
ll lb[MAX + 1];
int n, sz = 1;

double cross(int first, int sec) {
    return (double) (lb[sec] - lb[first]) / (la[first] - la[sec]);
}

void insert(ll a, ll b) {
    la[sz] = a;
    lb[sz] = b;

    while (sz > 2 && cross(sz - 1, sz - 2) > cross(sz, sz - 1)) {
        la[sz - 1] = la[sz];
        lb[sz - 1] = lb[sz];
        sz--;
    }
    ++sz;
}

ll query(ll x) {
    static int pos = 1;
    while (pos + 1 <= sz - 1 && cross(pos, pos + 1) <= x) ++pos;
    return la[pos] * x + lb[pos];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> height[i];
    }

    int cost;
    cin >> cost;

    insert(cost, 0);
    for (int j = 2; j <= n; ++j) {
        cin >> cost;
        dp[j] = query(height[j]);
        insert(cost, dp[j]);
    }

    cout << dp[n];

    return 0;
}
