#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<>> pq;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int num;
        cin >> num;
        pq.push(num);
    }

    int ret = 0;
    while (pq.size() > 1) {
        auto x = pq.top(); pq.pop();
        auto y = pq.top(); pq.pop();;

        ret += (x + y);
        pq.push(x + y);
    }

    cout << ret << "\n";
    return 0;
}
