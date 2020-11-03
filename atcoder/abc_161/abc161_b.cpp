#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;


int a[101];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        total += a[i];
    }

    sort(a, a + n, [](const auto & a, const auto & b) {
        return a > b;
    });

    double threshold = (1.0 / (4.0 * m)) * (double)total;

    for (int i = 0; i < m; ++i)
    {
        if ((double)a[i] < threshold) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}
