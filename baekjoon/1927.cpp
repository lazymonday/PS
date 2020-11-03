#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> pq;

    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        if (k == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << -pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(-k);
        }
    }

    return 0;
}
