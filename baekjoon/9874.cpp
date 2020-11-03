#include <bits/stdc++.h>

using namespace std;

const int MAX = 12;
const int INF = 1e9;
typedef long long ll;

int n;
pair<int, int> wh[MAX + 1];
int taken[MAX + 1];
int onright[MAX + 1];

bool checkCycle(int start)
{
    int p = start;
    for (int i = 0; i < n; ++i)
    {
        p = onright[taken[p]];
        if (p == -1) {
            return false;
        }
    }

    return true;
}

int solve() {

    int picked = -1;
    for (int i = 0; i < n; ++i) {
        if (taken[i] == -1) {
            picked = i;
            break;
        }
    }

    if (picked == -1) {
        for (int i = 0; i < n; ++i)
        {
            if (checkCycle(i)) return 1;
        }
        return 0;
    }

    int ans = 0;
    for (int i = picked + 1; i < n; ++i)
    {
        if (i == picked || taken[i] != -1) continue;
        taken[picked] = i;
        taken[i] = picked;
        ans += solve();
        taken[picked] = taken[i] = -1;
    }

    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wh[i].second >> wh[i].first;
    }

    memset(taken, -1, sizeof taken);
    memset(onright, -1, sizeof onright);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j) continue;
            if (wh[i].first == wh[j].first && wh[i].second < wh[j].second) {
                if (onright[i] == -1 || wh[j].second < wh[onright[i]].second) {
                    onright[i] = j;
                }
            }
        }
    }

    cout << solve();
    return 0;
}
