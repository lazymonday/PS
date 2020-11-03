#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1e3;
const int INF = 2e9;
typedef long long ll;

int row, col;
int a[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

pair<int, int> countZero() {
    int sum = 0;
    int maxVal = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!a[i][j]) sum++;
            maxVal = max(a[i][j], maxVal);
        }
    }

    return {sum, maxVal};
}



void bfs(vector<pair<int, int>>& sv) {

    queue<pair<int, int>> q;
    for (int i = 0; i < sv.size(); ++i)
    {
        q.push({sv[i].first, sv[i].second});
    }

    while (!q.empty()) {
        auto v = q.front();
        int rr = v.first;
        int cc = v.second;
        if (visited[rr][cc]) continue;
        visited[rr][cc] = true;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nr = rr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                continue;
            }
            if (!visited[nr][nc] && a[nr][nc] != -1 && a[nr][nc] != 1 && a[nr][nc] == 0) {
                a[nr][nc] = a[rr][cc] + 1;
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int, int>> sv;

    cin >> col >> row;
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                sv.push_back({i, j});
            }
        }

    auto ret = countZero();
    if (ret.first == 0) {
        cout << ret.second - 1;
        return 0;
    }

    bfs(sv);

    ret = countZero();
    if (ret.first == 0) {
        cout << ret.second - 1;
    } else {
        cout << -1;
    }
    return 0;
}
