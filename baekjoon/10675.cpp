#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
typedef long long ll;

int A, B, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int answer = INF;
    cin >> A >> B >> N;
    for (int i = 0; i < N; ++i)
    {
        int numOfRoute, cost;
        cin >> cost;
        cin >> numOfRoute;

        bool found = false;

        for (int j = 0; j < numOfRoute; ++j)
        {
            int next;
            cin >> next;
            if (!found && next == A) found = true;
            else if (found && next == B) {
                answer = min(answer, cost);
            }
        }
    }


    cout << (answer == INF ? -1 : answer);
    return 0;
}
