#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;

int n;
typedef pair<int, int> range;
range meet[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> meet[i].first >> meet[i].second;
    }

    sort(meet, meet + n, [](const range &a, const range &b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    int right = meet[0].second;
    int count = 1;
    for (int j = 1; j < n; ++j) {
        if (right <= meet[j].first) {
            count++;
            right = meet[j].second;
        }
    }

    cout << count;

    return 0;
}
