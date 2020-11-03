#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 40100;
int nums[MAX];
int L[MAX];
int n;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    int len = 0;
    for (int j = 1; j <= n; ++j) {
        auto pos = lower_bound(L, L + len, nums[j]);
        *pos = nums[j];
        auto dist = pos - L;
        if (dist == len) ++len;
    }

    cout << len;

    return 0;
}
