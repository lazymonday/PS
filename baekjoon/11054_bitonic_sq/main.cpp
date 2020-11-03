#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1011;
int nums[MAX];
int dp1[MAX];
int dp2[MAX];
int n;

void lis() {
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                count = max(count, dp1[j]);
            }
        }

        dp1[i] = count + 1;
    }
}

void lis_reverse() {
    for (int i = n - 1; i >= 0; --i) {
        int count = 0;
        for (int j = i; j < n; ++j) {
            if (nums[i] > nums[j]) {
                count = max(count, dp2[j]);
            }
        }

        dp2[i] = count + 1;
    }
}


int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    lis(), lis_reverse();

    int ans = 0;
    for (int j = 0; j < n; ++j) {
        ans = max(ans, dp1[j] + dp2[j]);
    }

    cout << ans - 1 << "\n";

    return 0;
}
