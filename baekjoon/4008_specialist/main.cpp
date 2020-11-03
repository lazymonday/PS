#include <iostream>

using namespace std;

typedef long long ll;
const int MAX = 1e6;
int a, b, c;
int n;
ll s[MAX + 1];

int cnt = 1;
struct segment {
    ll a, b;
};

segment lines[MAX];

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
    static int pos = 1;
    while (pos + 1 < cnt && cross(pos, pos + 1) <= x) pos++;
    return lines[pos].a * x + lines[pos].b;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> a >> b >> c;

    int num;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        s[i] = s[i - 1] + num;
    }

    ll dp = 0;
    insert(0, 0);
    for (int i = 1; i <= n; ++i) {
        dp = query(s[i]) + a * s[i] * s[i] + b * s[i] + c;
        insert(-2ll * a * s[i], a * s[i] * s[i] - b * s[i] + dp);
    }

    cout << dp << "\n";


    return 0;
}
