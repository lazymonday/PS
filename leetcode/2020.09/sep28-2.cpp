#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll numSubarrayProductLessThanK(vector<int>& a, int k) {
    int n = a.size();
    ll prod = 1, ans = 0;

    int st = 0;
    for (int e = 0; e < n; ++e) {
        prod *= a[e];
        while(prod >= k && st < e) {
            prod /= a[st];
            ++st;
        }

        ans += (e-st+1);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("sep29-1.in", "r", stdin);

    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cin >> k;
    cout << numSubarrayProductLessThanK(nums, k);

    return 0;
}