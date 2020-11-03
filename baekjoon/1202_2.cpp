#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = 3e5;
const int INF = 2e9;
typedef long long ll;

int n, k;
pair<int, int> a[MAX + 1];  // first : worth, second : weight
multiset<int> bags;

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
        int bag;
        cin >> bag;
        bags.insert(bag);
    }

    sort(a, a + n, [](const auto & a, const auto & b) {
        return a.first == b.first ? a.second < b.second : a.first > b.first;
    });

    ll total = 0;
    for (int i = 0; i < n; ++i)
    {
        auto pos = bags.lower_bound(a[i].second);
        if (pos != bags.end()) {
            bags.erase(pos);
            total += (1ll * a[i].first);
        }

        if (bags.size() == 0) {
            break;
        }
    }

    cout << total;

    return 0;
}
