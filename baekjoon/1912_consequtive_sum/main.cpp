#include <iostream>

using namespace std;

const int INF = 1e9;
const int MAX = 1e5;
int nums[MAX + 1];
int n;

int findCrossingMax(int left, int right);

int solve(int left, int right) {
    if (left == right) {
        return nums[left];
    }

    int mid = left + (right - left) / 2;
    int candidate = max(solve(left, mid), solve(mid + 1, right));
    candidate = max(candidate, findCrossingMax(left, right));

    return candidate;
}

int findCrossingMax(int left, int right) {
    if (left == right) return nums[left];
    int mid = left + (right - left) / 2;
    int l = mid, r = mid + 1;

    int leftSum = -INF;
    int sum = 0;
    while (left <= l) {
        sum += nums[l--];
        leftSum = max(leftSum, sum);
    }

    int rightSum = -INF;
    sum = 0;
    while (r <= right) {
        sum += nums[r++];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int ret = -INF;
    int sum = 0;
    int num;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        sum += num;
        ret = max(ret, sum);
        if (sum < 0) sum = 0;
    }

    cout << ret;

    return 0;
}


int main2() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    int ans = solve(1, n);
    cout << ans;

    return 0;
}
