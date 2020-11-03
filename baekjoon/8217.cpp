#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5;
const int INF = 1e9;
typedef long long ll;

struct Query {
    int l, r, val;
};

struct State {
    int lo, hi;
    vector<int> sectors;
};

int n, m, q;
State states[MAX + 1];
int goal[MAX + 1];
Query queries[MAX + 1];
ll tree[MAX + 1];

void init() {
    memset(tree, 0, sizeof tree);
}

void add(int p, ll val) {
    while (p <= m) {
        tree[p] += val;
        p += (p & -p);
    }
}

ll sum(int p) {
    ll ret = 0;
    while (p > 0) {
        ret += tree[p];
        p -= (p & -p);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;  // n : states, m : sectors
    int sector;
    for (int i = 1; i <= m; ++i) {
        cin >> sector;
        states[sector].sectors.push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        cin >> goal[i];
    }

    cin >> q;

    for (int i = 1; i <= n; ++i) {
        states[i].lo = 1;
        states[i].hi = q + 1;
    }

    int left, right, value;
    for (int i = 1; i <= q; ++i)
    {
        cin >> left >> right >> value;
        queries[i] = {left, right, value};
    }

    while (true) {

        init();

        bool done = true;
        vector<int> mids[MAX + 1];
        for (int i = 1; i <= n; ++i)
        {
            if (states[i].lo >= states[i].hi) continue;
            int x = states[i].lo + ((states[i].hi - states[i].lo) >> 1);
            mids[x].push_back(i);
            done = false;
        }

        if (done) break;

        for (int i = 1; i <= q; ++i) {
            int left = queries[i].l, right = queries[i].r, value = queries[i].val;
            if (left <= right) {
                add(left, value);
                add(right + 1, -value);
            } else {
                add(1, value);
                add(right + 1, -value);
                add(left, value);
            }

            for (int k = 0; k < mids[i].size(); ++k)
            {
                int stateId = mids[i][k];
                ll ans = 0;
                for (auto secId : states[stateId].sectors) {
                    ans += sum(secId);
                    if (ans >= goal[stateId]) break;
                }

                if (ans < goal[stateId]) {
                    states[stateId].lo = i + 1;
                } else {
                    states[stateId].hi = i;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (states[i].lo == q + 1) cout << "NIE\n";
        else cout << states[i].lo << "\n";
    }

    return 0;
}


