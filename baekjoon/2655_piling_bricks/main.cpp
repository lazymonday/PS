#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Brick {
    int index, area, height, weight;

    bool operator<(const Brick &rhs) const {
        return area < rhs.area;
    }
};

const int MAX = 100;
int n;
Brick bricks[MAX + 1];
int dp[MAX + 1];
int dp2[MAX + 1];
int last[MAX + 1];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int k = 1; k <= n; ++k) {
        bricks[k].index = k;
        cin >> bricks[k].area >> bricks[k].height >> bricks[k].weight;
    }

    sort(bricks + 1, bricks + n + 1);

    int largest = 0;
    int maxHeight = 0;
    for (int i = 1; i <= n; ++i) {
        int height = 0;
        for (int j = 1; j < i; ++j) {
            if (bricks[i].weight > bricks[j].weight) {
                if (height < dp[j]) {
                    height = max(height, dp[j]);
                    last[i] = j;
                }
            }
        }

        dp[i] = height + bricks[i].height;
        if (maxHeight < dp[i]) {
            maxHeight = dp[i];
            largest = i;
        }
    }

    stack<int> st;
    st.push(bricks[largest].index);
    while (last[largest] != 0) {
        st.push(bricks[last[largest]].index);
        largest = last[largest];
    }

    cout << st.size() << "\n";

    while (!st.empty()) {
        cout << st.top() << "\n";
        st.pop();
    }

    return 0;
}
