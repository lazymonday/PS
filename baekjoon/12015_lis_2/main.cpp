#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int MAX = 1e6 + 1;
vector<int> nums;

int n;
int dp[MAX];
int parent[MAX];

int lis_iterate(int size) {

    int ans = 0;
    for (int i = 0; i < size; ++i) {
        int count = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (count < dp[j] + 1) {
                    count = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
        dp[i] = count;
        if (ans < dp[i]) {
            ans = dp[i];
            parent[size] = i;
        }
    }

    cout << ans << "\n";

    stack<int> st;
    int pos = parent[size];
    for (int k = 0; k < ans; ++k) {
        st.push(nums[pos]);
        pos = parent[pos];
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << "\n";

    return ans;
}

int lis(int start) {

    int ret = 1;
    for (int next = start + 1; next < n; ++next) {
        if (start == -1 || nums[start] < nums[next]) {
            ret = max(ret, lis(next) + 1);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    lis_iterate(n);
    return 0;
}
