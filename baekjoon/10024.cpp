#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e2;
const int INF = 1e9;
typedef long long ll;

int n;
int order[MAX + 5][2];
int nxt[MAX + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> order[i][0];
    for (int i = 1; i <= n; ++i) cin >> order[i][1];
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (order[i][0] == order[j][1]) {
                nxt[i] = j;
                break;
            }

    int numCycles = 0;
    int maxCycles = 0;

    for (int i = 1; i <= n; ++i)
    {
        if(nxt[i] == 0) continue;
        
        int idx = i, depth = 1;
        int lessCnt = 0, greaterCnt = 0;
        while (nxt[idx] != i && nxt[idx]) {
            if (idx < nxt[i]) {
                lessCnt++;
            } else {
                greaterCnt++;
            }
            idx = nxt[idx];
            depth++;
        }

        if (nxt[idx] && (greaterCnt == 1 || lessCnt == 1)) {
            numCycles++;
            maxCycles = max(depth, maxCycles);
            nxt[i] = 0;
        }
    }

    cout << numCycles << " " << (maxCycles == 0 ? -1 : maxCycles);

    return 0;
}
