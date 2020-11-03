#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6 + 10;
int n;
int nums[MAX];
int lisArr[MAX];

bool comp(const int& a, const int& b) { return a > b;}

int lis() {
    int len = 0;
    for (int i = 0; i < n; ++i) {
        auto pos = lower_bound(lisArr, lisArr + len, nums[i], comp);
        *pos = nums[i];
        if (pos == lisArr + len) {
            len++;
        }
    }

    return len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int len = lis();
    cout << len << "\n";

    return 0;
}
