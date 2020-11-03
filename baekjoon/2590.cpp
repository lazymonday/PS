#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int a[7];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 6; ++i)
    {
        cin >> a[i];
    }

    cout << solve(0);

    return 0;
}
