#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;
const int INF = 1e9;
typedef long long ll;

int N;
int hay[MAX];
bool exploded[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> hay[i];
    }

    sort(hay, hay + N);

    int ans = 0;
    for (int i = 0; i < N; ++i) {

        memset(exploded, false, sizeof exploded);

        queue<pair<int, int>> blast;
        blast.push({i, 1});
        exploded[i] = true;
        int cand = 1;
        while (!blast.empty()) {
            int pos = blast.front().first;
            int rad = blast.front().second;
            blast.pop();

            for (int j = 1; j <= rad; ++j)
            {
                if (pos + j < N && !exploded[pos + j] && hay[pos + j] - hay[pos] <= rad) {
                    blast.push({pos + j, rad + 1});
                    exploded[pos + j] = true;
                    cand++;
                }

                if (pos - j >= 0 && !exploded[pos - j] && hay[pos] - hay[pos - j] <= rad) {
                    blast.push({pos - j, rad + 1});
                    exploded[pos - j] = true;
                    cand++;
                }
            }
        }


        ans = max(ans, cand);
    }

    cout << ans;

    return 0;
}
