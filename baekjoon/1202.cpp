#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 3e5;
const int INF = 2e9;
typedef long long ll;

int n, k;
pair<int, int> a[MAX + 1];  // first : worth, second : weight
pair<int, bool> bag[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].second >> a[i].first;
    }

    for (int i = 0; i < k; ++i)
    {
        cin >> bag[i].first;
        bag[i].second = false;
    }

    sort(a, a + n, [](const auto & a, const auto & b) {
        return a.first == b.first ? a.second < b.second : a.first > b.first;
    });
    sort(bag, bag + k, [](const auto & a, const auto & b) {
        return a.first < b.first;
    });

    ll total = 0;
    int occupied = 0;
    for (int i = 0; i < n; ++i)
    {
        auto pos = lower_bound(bag, bag + k, pair<int, bool>{a[i].second, false});

        int dist = pos - bag;
        if (dist < k && pos->second == false) {
            pos->second = true;
            occupied++;
            total += a[i].first;
        }

        if(occupied == k) {
            break;
        }
    }


    cout << total;

    return 0;
}
