#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int a[MAX + 1];
int n;

int psum(int k) {
    if (k < 0) {
        return 0;
    }

    return (a[k] = psum(k - 1) + a[k]);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    psum(n - 1);

    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ", ";
    }

    return 0;
}
