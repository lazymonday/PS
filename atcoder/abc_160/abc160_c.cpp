#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2e5;
const int INF = 2e9;
typedef long long ll;

int a[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> k >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    int maxdiff = 0;
    for (int i = 1; i < n; ++i)
    {
        maxdiff = max(maxdiff, a[i] - a[i - 1]);
    }
    maxdiff = max(maxdiff, k - a[n - 1] + a[0]);

    cout << k - maxdiff;


    return 0;
}
