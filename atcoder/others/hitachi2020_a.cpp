#include <iostream>

using namespace std;

typedef long long ll;
const int MAX = 2e5;
int n, t;
pair<int, int> arr[MAX + 1];

struct segment {
    ll a, b;
};

segment lines[MAX + 1];
int cnt = 1;

double cross(const int &a, const int &b) {
    return (double) (lines[b].b - lines[a].b) / (double) (lines[a].a - lines[b].a);
}

void insert(ll c1, ll c2) {
    lines[cnt] = {c1, c2};
    while (cnt > 2 && cross(cnt, cnt - 1) < cross(cnt - 1, cnt - 2)) {
        lines[cnt - 1] = lines[cnt];
        cnt--;
    }

    ++cnt;
}

ll query(ll x) {
    int l = 0, r = cnt;
    while (l != r) {
        int m = (l + r) / 2;
        if (cross(m, m + 1) <= x) l = m + 1;
        else r = m;
    }

    return lines[l].a * x + lines[l].b;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr + 1, arr + n + 1);

    insert(0, 1);
    ll ans = 0;
    ll time = 1;
    for (int j = 1; j <= n; ++j) {
        time += query(time);
        time++;
        if (time > t) {
            break;
        }
        insert(arr[j].first, arr[j].second);
        ++ans;
    }

    cout << ans;


    return 0;
}