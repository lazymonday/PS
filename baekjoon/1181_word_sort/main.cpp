#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2e4;
const int INF = 2e9;
typedef long long ll;

int n;
string a[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n, [](const string &a, const string &b) {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });

    for (int j = 0; j < n; ++j) {
        if (j > 0 && a[j] == a[j-1]) {
            continue;
        }
        cout << a[j] << "\n";
    }

    return 0;
}
