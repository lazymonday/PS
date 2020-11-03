#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;

int n;
typedef pair<int, int> Point;
Point coords[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> coords[i].first >> coords[i].second;
    }

    sort(coords, coords + n, [](const Point &a, const Point &b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    for (int i = 0; i < n; ++i) {
        cout << coords[i].first << " " << coords[i].second << "\n";
    }

    return 0;
}
