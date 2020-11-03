#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

const int MAX = 100;
const int INF = 2e9;
typedef long long ll;

int cases;
typedef pair<int, int> task;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> cases;
    int n, m;
    while (cases--) {
        cin >> n >> m;
        deque<task> dq;
        for (int i = 0; i < n; ++i) {
            int p;
            cin >> p;
            dq.emplace_back(p, i);
        }

        int printed = 0;
        while (!dq.empty()) {
            auto t = dq.front();
            bool larger = false;
            for (int i = 1; i < dq.size(); ++i) {
                if (dq[i].first > t.first) {
                    larger = true;
                    break;
                }
            }

            if (larger) {
                dq.push_back(dq.front());
                dq.pop_front();
            } else {
                printed++;
                if (dq.front().second == m) {
                    cout << printed << "\n";
                }
                dq.pop_front();
            }
        }
    }

    return 0;
}
