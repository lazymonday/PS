#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 1e4;
typedef long long ll;
int n, m;
int nums[MAX + 1];
int psum[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int largest = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        largest = max(largest, nums[i]);
        psum[i] = psum[i - 1] + nums[i];
    }

    int lo = largest - 1;
    int hi = 1e9;

    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;

        auto can = [&]() {
            int count = 1;
            int last = 0;
            for (int i = 0; i < n; ++i) {
                if (psum[i + 1] - psum[last] > mid) {
                    count++;
                    last = i;
                }
            }

            return m < count;
        };

        if (can()) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << " " << hi;
    return 0;
}
