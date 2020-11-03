#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 50;
const int INF = 2e9;
typedef long long ll;

int n;
int a[MAX + 1];
int b[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n, [](const int &a, const int &b) {
        return a > b;
    });

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    sort(b, b + n);

    int sum = 0;
    for (int j = 0; j < n; ++j) {
        sum += a[j] * b[j];
    }

    cout << sum;
    return 0;
}
