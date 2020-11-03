#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 5e5;
const int INF = 2e9;
typedef long long ll;

int n, m;
int a[MAX + 1];

bool bs(int lo, int hi, int k) {

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    return a[lo] == k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    cin >> m;
    int k;
    for (int j = 0; j < m; ++j) {
        cin >> k;
        cout << (bs(0, n, k) ? "1 " : "0 ");
    }

    return 0;
}
