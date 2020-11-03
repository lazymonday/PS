#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAX = 75000;
const int TREE_MAX = 1 << 18;
int t;
int n;
int tree[TREE_MAX];

void add(int pos) {
    while (pos < TREE_MAX) {
        tree[pos]++;
        pos += (pos & -pos);
    }
}

int sum(int pos) {
    int ret = 0;
    while (pos > 0) {
        ret += tree[pos];
        pos -= (pos & -pos);
    }

    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> islands(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> islands[i].first >> islands[i].second;
        }

        sort(islands.begin() + 1, islands.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second < rhs.second;
        });

        int temp[MAX + 1], cur = 1;
        temp[1] = cur;
        for (int k = 2; k <= n; ++k) {
            if (islands[k].second != islands[k - 1].second) ++cur;
            temp[k] = cur;
        }

        for (int k = 1; k <= n; ++k) {
            islands[k].second = temp[k];
        }

        sort(islands.begin() + 1, islands.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
            if (lhs.first != rhs.first) return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        });

        long long ans = 0;
        for (int j = 1; j <= n; ++j) {
            ans += (sum(n) - sum(islands[j].second - 1));
            add(islands[j].second);
        }

        cout << ans << "\n";

        memset(tree, 0, sizeof tree);
    }

    return 0;
}
