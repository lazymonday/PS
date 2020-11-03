#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
int line[MAX + 1];
int L[MAX + 1];
int n;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int to;
    for (int k = 1; k <= n; ++k) {
        cin >> to;
        line[k] = to;
    }

    int len = 0;
    for (int i = 1; i <= MAX; ++i) {
        auto pos = lower_bound(L, L + len, line[i]);
        int dist = pos - L;
        *pos = line[i];
        if (dist == len) {
            len++;
        }
    }

    cout << n - len << "\n";

    return 0;
}
