#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 5000;
bool visited[MAX + 1];
int visitCount;

inline void visit(int i) {
    visited[i] = true;
    visitCount++;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> timber(n);
        for (int i = 0; i < n; ++i) {
            cin >> timber[i].first;
            cin >> timber[i].second;
        }

        sort(timber.begin(), timber.end());

        memset(visited, false, sizeof visited);

        int ans = 0;
        visitCount = 0;
        int nextPivot = 0;
        while (visitCount < n) {
            int pivot = nextPivot;
            nextPivot = -1;
            visit(pivot);

            for (int i = pivot + 1; i < n; ++i) {
                if (visited[i]) continue;
                if (timber[pivot].second <= timber[i].second) {
                    visit(i);
                    pivot = i;
                } else if (nextPivot == -1) {
                    nextPivot = i;
                }
            }
            ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
