#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;


int a[9];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    for (int i = 0; i < 9; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + 9);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (sum - a[i] - a[j] == 100) {
                for (int k = 0; k < 9; ++k)
                {
                    if (k == i || k == j) continue;
                    cout << a[k] << "\n";
                }
                return 0;
            }
        }
    }

    return 0;
}
