#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int n;
int a[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int move;
        cin >> move;
        for (int j = 0; j < move; ++j)
        {
            a[i - j] = a[i - j - 1];
        }
        a[i - move] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << " ";
    }

    return 0;
}
