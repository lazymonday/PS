#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

int n, k;
pair<int, int> grass[MAX + 1];
int psum[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    int gr, pos;
    for (int i = 0; i < n; ++i)
    {
        cin >> gr >> pos;
        grass[i] = {pos, gr};
    }

    sort(grass, grass + n);
    psum[0] = grass[i].second;
    for (int i = 1; i < n; ++i) {
        psum[i] = psum[i - 1] + grass[i].second;
    }

    int left = 0;
    int right = 0;
    int ans = 0;
    while (right < n)
    {
        int cand = 0;
        if (grass[right].first - grass[left].first <= 2 * k) {
            cand = psum[min(n - 1, right)] - (!left ? 0 : psum[left - 1]);
            ++right;
        } else {
            ++left;
        }

        ans = max(ans, cand);
    }

    cout << ans;

    return 0;
}
