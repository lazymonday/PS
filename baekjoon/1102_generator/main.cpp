#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned short ushort;
const int INF = 1e9;
const int MAX = 65536;
int dp[MAX];


int n;
int adj[16][16];

int solve(ushort current, int toKeep);

int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }

    string status;
    cin >> status;
    ushort current = 0;
    for (int k = 0; k < status.size(); ++k) {
        if (status[k] == 'Y') {
            current |= (1 << k);
        }
    }

    int minCount = 0;
    cin >> minCount;

    for (int l = 0; l < MAX; ++l) {
        dp[l] = INF;
    }

    if (current == 0 && minCount != 0) {
        cout << -1 << endl;
    } else {
        cout << solve(current, minCount) << endl;
    }

    return 0;
}

bool getBits(ushort state, int k) {
    return (state & (1 << k)) != 0;
}

int solve(ushort current, int toKeep) {
    if (__builtin_popcountll(current) >= toKeep) {
        return 0;
    }

    int &ret = dp[current];
    if (ret != INF) {
        return ret;
    }

    for (int i = 0; i < n; ++i) {
        if (!getBits(current, i)) {
            continue;
        }

        for (int j = 0; j < n; ++j) {
            if (getBits(current, j)) continue;
            ushort next = current | (1 << j);
            ret = min(ret, solve(next, toKeep) + adj[i][j]);
        }
    }

    return ret;
}