#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 20;
const int INF = 2e9;
typedef long long ll;

int n, s;
int a[MAX + 1];

int solve(int tried, int sum, int choosed) {
    if (tried >= n) {
        return sum == s && choosed > 0 ? 1 : 0;
    }

    return solve(tried + 1, sum + a[tried], choosed + 1) + solve(tried + 1, sum, choosed);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << solve(0, 0, 0);
    return 0;
}
