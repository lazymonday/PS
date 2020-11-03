#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int N, B;
pair<int, int> cx[105];
pair<int, int> cy[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> B;

    for (int i = 0; i < N; ++i)
    {
        cin >> cx[i].first >> cx[i].second;
        cy[i] = cx[i];
    }

    sort(cx, cx + N);
    sort(cy, cy + N, [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second < rhs.second;
    });

    int ans = INF;
    int left = 0, right;
    for (int i = 0; i < N; ++i)
    {
        left++;
        if (i < N - 1 && cx[i].first == cx[i + 1].first) {
            continue;
        }

        right = N - left;

        int lu = left, lb = 0;
        int ru = right, rb = 0;

        int cntl = 0, cntr = 0;
        for (int j = 0; j < N; ++j)
        {
            if (cy[j].first <= cx[i].first) {
                cntl++;
            } else {
                cntr++;
            }

            if (j < N - 1 && cy[j].second == cy[j + 1].second) {
                continue;
            }

            lu = left - cntl;
            lb = cntl;
            ru = right - cntr;
            rb = cntr;
            ans = min(ans, max({lu, lb, ru, rb}));
        }
    }

    cout << ans;
    return 0;
}
