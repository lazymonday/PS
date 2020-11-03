#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<>> minq;

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        if (minq.size() == maxq.size()) {
            maxq.push(k);
        } else {
            minq.push(k);
        }

        // invalidate
        // assert(minq.top() > maxq.top())
        if (minq.size() > 0 && maxq.size() > 0 && maxq.top() > minq.top()) {
            int t = minq.top(); minq.pop();
            int tt = maxq.top(); maxq.pop();
            minq.push(tt);
            maxq.push(t);
        }

        cout << maxq.top() << "\n";
    }

    return 0;
}
