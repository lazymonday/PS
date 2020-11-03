#include <iostream>
#include <algorithm>

using namespace std;

struct guest {
    int s, e;
};

const int MAX = 3e5;
int n, m;
guest clients[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int sz = 0;
    for (int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;
        if (s < e) continue;
        clients[sz].s = s;
        clients[sz].e = e;
        sz++;
    }

    sort(clients, clients + sz, [](const guest &a, const guest &b) {
        return a.e < b.e;
    });

    long long ans = m;
    int ep = clients[0].e;
    int sp = clients[0].s;
    for (int j = 1; j < sz; ++j) {
        if (ep <= clients[j].e && clients[j].e <= sp) {
            sp = max(clients[j].s, sp);
        } else {
            ans += (sp - ep) * 2ll;
            ep = clients[j].e;
            sp = clients[j].s;
        }
    }
    ans += (sp - ep) * 2ll;

    cout << ans;

    return 0;
}
