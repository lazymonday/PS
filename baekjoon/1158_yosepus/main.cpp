#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 5e3;
const int INF = 2e9;
typedef long long ll;

int n, k;
int a[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    k--;
    cout << "<";
    int index = 0;
    int count = n;
    for (int j = 0; j < n; ++j) {
        index = (index + k) % count;
        if (j != 0) cout << ", ";
        cout << a[index];
        for (int i = index; i < n - 1; ++i) {
            a[i] = a[i + 1];
        }
        count--;
    }
    cout << ">";
    return 0;
}
