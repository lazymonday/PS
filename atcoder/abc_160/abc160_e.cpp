#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;


template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for (T &in : v) is >> in;
    return is;
}


int x, y, ca, cb, cc;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y >> ca >> cb >> cc;

    vector<int> A(ca);
    vector<int> B(cb);
    vector<int> C(cc);

    cin >> A >> B >> C;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    while (A.size() > x) A.pop_back();
    while (B.size() > y) B.pop_back();

    vector<int> merged{A};
    for (int i = 0; i < B.size(); ++i)
    {
        merged.emplace_back(B[i]);
    }

    sort(merged.begin(), merged.end());
    sort(C.rbegin(), C.rend());

    ll add = 0;
    for (int i = 0; i < cc && i < merged.size(); ++i)
    {
        if (C[i] > merged[i]) add += C[i] - merged[i];
    }

    ll ans = accumulate(merged.begin(), merged.end(), add);
    cout << ans;

    return 0;
}
