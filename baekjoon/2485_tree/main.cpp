#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

int n;
int a[MAX + 1];

int gcd(int a, int b) {
    int r = a % b;
    while (r > 0) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int gc = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    gc = gcd(a[2] - a[1], a[1] - a[0]);
    for (int i = 3; i < n; ++i) {
        gc = gcd(gc, a[i] - a[i - 1]);
    }

    cout << (a[n - 1] - a[0]) / gc + 1 - n;

    return 0;
}
