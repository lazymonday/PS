#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 5e5;
const int INF = 1e7;
typedef long long ll;

int n, m;
int a[INF * 2 + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        a[t + INF]++;
    }

    cin >> m;
    for (int j = 0; j < m; ++j) {
        cin >> t;
        cout << a[t + INF] << " ";
    }

    return 0;
}
