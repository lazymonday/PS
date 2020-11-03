#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

struct Cow {
    int index, arrival, eating;
};

bool comp1(const Cow& lhs, const Cow& rhs) {
    if (lhs.arrival == rhs.arrival) {
        return lhs.index < rhs.index;
    }
    return lhs.arrival < rhs.arrival;
}

struct comp2 {
    bool operator() (const Cow& lhs, const Cow& rhs) const {
        return lhs.index > rhs.index;
    }
};

int n;
Cow cows[MAX + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int a, t;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> t;
        cows[i] = {i+1, a, t};
    }

    sort(cows, cows + n, comp1);
    int ans = 0;
    int idx = 0;
    int eaten = 0;
    int curr_t = 0;
    priority_queue<Cow, vector<Cow>, comp2> pq;
    while (eaten < n) {
        if (!pq.empty()) {
            auto cow = pq.top();
            pq.pop();
            ans = max(ans, curr_t - cow.arrival);
            curr_t += cow.eating;
            eaten++;
        } else {
            curr_t = cows[idx].arrival + cows[idx].eating;
            eaten++, idx++;
        }

        while (idx < n && curr_t >= cows[idx].arrival) {
            pq.push(cows[idx]);
            ++idx;
        }
    }

    cout << ans;

    return 0;
}
