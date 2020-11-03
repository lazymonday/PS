#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> nums;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i].first >> nums[i].second;
    }

    sort(nums.begin(), nums.end());

    int l = nums[0].first, r = nums[0].second;
    int ans = r - l;
    for (int j = 1; j < n; ++j) {
        if (nums[j].first <= r) {
            ans += max(0, (nums[j].second - r));
            r = max(r, nums[j].second);
        } else {
            l = nums[j].first;
            r = nums[j].second;
            ans += (r - l);
        }
    }

    cout << ans;

    return 0;
}
