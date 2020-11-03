#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int n;
int a[50];
int taken[50];

void next(int tried, vector<int> &ret) {
    if (tried >= n) {
        if (ret.size() == 6) {
            for (int i = 0; i < ret.size(); ++i) {
                cout << ret[i] << " ";
            }
            cout << "\n";
            return;
        }
        return;
    }

    ret.push_back(a[tried]);
    next(tried + 1, ret);
    ret.pop_back();
    next(tried + 1, ret);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> n;
        if (n == 0) break;

        memset(taken, -1, sizeof taken);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a, a + n);
        vector<int> ret;
        next(0, ret);

        cout << "\n";
    }

    return 0;
}
