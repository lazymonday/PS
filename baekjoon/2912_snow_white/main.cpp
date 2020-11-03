#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 300100;
int n, c, m;
int rt = 3000;  // sqrt(n^2/q)   # n^2 / bucket = q * bucket
int caps[MAX];
int freq[10010];
int answer[10010];

struct Query {
    int i, l, r;

    bool operator<(const Query &rhs) const {
        int l0 = l / rt;
        int l1 = rhs.l / rt;
        return l0 == l1 ? r < rhs.r : l < rhs.l;
    }
};

void add(int color) {
    ++freq[color];
}

void remove(int color) {
    --freq[color];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> caps[i];
    }

    rt = 3300;
    cin >> m;

    vector<Query> q(m);
    for (int i = 0; i < m; ++i) {
        q[i].i = i;
        cin >> q[i].l >> q[i].r;
    }

    sort(q.begin(), q.end());
    int left = 0, right = 0;
    for (int i = 0; i < m; ++i) {
        while (left < q[i].l) remove(caps[left++]);
        while (left > q[i].l) add(caps[--left]);
        while (right < q[i].r) add(caps[++right]);
        while (right > q[i].r) remove(caps[right--]);

        for (int k = 1; k <= c; ++k) {
            // 현재 상태의 freq이므로 해당 숫자가 있는지 선형으로 찾아도 됨 (1만개 밖에 안되서)
            if ((right - left + 1) / 2 < freq[k]) {
                answer[q[i].i] = k;
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        if (answer[i] == 0) {
            cout << "no\n";
        } else {
            cout << "yes " << answer[i] << "\n";
        }
    }

    return 0;
}
