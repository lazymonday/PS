#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 123456;
const int INF = 1e6;
typedef long long ll;

int n, atk;

struct room {
    int t, atk, hp;
};

room r[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> atk;
    for (int i = 0; i < n; ++i) {
        cin >> r[i].t >> r[i].atk >> r[i].hp;
    }

    ll lo = 1;
    ll hi = MAX * 1e12 + 1;

    while (lo < hi) {
        ll maxHp = lo + (hi - lo) / 2;
        auto can = [&]() {
            ll newAtk = atk;
            ll curHp = maxHp;
            bool defeat = false;
            for (int i = 0; i < n; ++i) {
                if (r[i].t == 1) {
                    ll ac = ceil(r[i].hp / (double) newAtk);
                    ll mc = ceil(curHp / (double) r[i].atk);
                    if (mc < ac) {
                        defeat = true;
                        break;
                    }
                    curHp -= (ac - 1) * r[i].atk;
                } else {
                    newAtk += r[i].atk;
                    curHp = min(maxHp, curHp + r[i].hp);
                }
            }

            return defeat;
        };

        if (can()) {
            lo = maxHp + 1;
        } else {
            hi = maxHp;
        }
    }

    cout << lo;

    return 0;
}
