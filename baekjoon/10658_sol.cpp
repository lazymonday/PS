#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e4;
const int INF = 2e9;
typedef long long ll;

int N, A, B;
pair<int, int> weight[MAX + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("learning_bronze/7.in", "r", stdin);

    cin >> N >> A >> B;

    for (int i = 0; i < N; ++i)
    {
        string s;
        int w;
        cin >> s >> w;
        weight[i] = {w, (s == "S" ? 1 : 0)};
    }

    weight[N++] = {INF, 0};
    weight[N++] = { -INF, 0};

    int ans = 0;
    sort(weight, weight + N);
    for (int i = 0; i < N - 1; ++i)
    {
        int begin = weight[i].first;
        int end = weight[i + 1].first;
        int mid = (begin + end) / 2;

        if (weight[i].second) {
            int b = max(A, begin + 1);
            int e = min(B, mid);
            if (e >= b) {
                ans += e - b + 1;
            }
        }

        if (weight[i + 1].second) {
            int b = max(A, mid + 1);
            int e = min(B, end);
            if (e >= b) {
                ans += e - b + 1;
            }
        }

        if (!weight[i].second && weight[i + 1].second && (begin % 2) == (end % 2) && A <= mid && mid <= B) ans++;
    }

    cout << ans;

    return 0;
}