#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2e3;
const int INF = 2e9;
typedef long long ll;

int ans[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (i == j) continue;
            if ((j <= x && i <= x) || (j >= y && i >= y)) {
                ans[i - j]++;
            } else {
                if (j <= x && i <= y) {
                    ans[min(i - j, x - j + 1 + y - i)]++;
                } else if (x <= j && i <= y) {
                    ans[min(i - j, j - x + 1 + y - i)]++;
                } else if (x <= j && y <= i) {
                    ans[min(i - j, 1 + j - x + i - y)]++;
                } else if (j <= x && y <= i) {
                    ans[min(i - j, x - j + 1 + i - y)]++;
                }
            }
        }
    }

    for (int i = 1; i < n; ++i)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
