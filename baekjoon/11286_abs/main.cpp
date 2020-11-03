#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

struct comp {
    bool operator()(const int &a, const int &b) const {
        int aa = abs(a), bb = abs(b);
        return aa == bb ? a > b : aa > bb;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, comp> pq;
    while (n--) {
        int k;
        cin >> k;
        if (k != 0) {
            pq.push(k);
        } else {
            if (pq.empty()) {
                cout << 0 << "\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}
