#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long ll;

ll sweep(vector<int> &height) {
    stack<int> remain;

    ll ret = 0;
    for (int i = 0; i < height.size(); ++i) {

        while (!remain.empty() && height[remain.top()] >= height[i]) {
            int pivot = remain.top();
            remain.pop();

            ll width = i;
            if (!remain.empty()) {
                width = (i - remain.top() - 1);
            }
            ll h = height[pivot];

            ret = max(ret, width * h);
        }

        remain.push(i);
    }

    return ret;
}

ll dnq(vector<int> &height, int left, int right) {
    if (left >= right) {
        return height[left];
    }

    int mid = left + (right - left) / 2;
    ll la = dnq(height, left, mid);
    ll ra = dnq(height, mid + 1, right);

    // merge
    int lhs = mid;
    int rhs = mid + 1;
    int h = min(height[lhs], height[rhs]);
    ll candidate = h * (rhs - lhs + 1);
    while (left < lhs || rhs < right) {
        if (left < lhs && (rhs >= right || height[lhs - 1] > height[rhs + 1])) {
            --lhs;
        } else {
            ++rhs;
        }

        h = min(h, min(height[lhs], height[rhs]));
        candidate = max(candidate, (ll) h * (rhs - lhs + 1));
    }

    return max(candidate, max(la, ra));
}

int main() {

    int num = -1;
    while (num != 0) {
        scanf("%d", &num);
        if (num) {
            vector<int> rect(num, 0);
            for (int i = 0; i < num; ++i) {
                scanf("%d", &rect[i]);
            }

            //ll ret = sweep(rect);
            ll ret = dnq(rect, 0, num - 1);
            printf("%lld\n", ret);
        }
    }
    return 0;
}
