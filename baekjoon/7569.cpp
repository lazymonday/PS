#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1e2;
const int INF = 2e9;
typedef long long ll;

int row, col, height;
int a[MAX + 1][MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1][MAX + 1];
int dr[] = {0, 0, 1, -1, 0, 0};
int dc[] = {1, -1, 0, 0, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};

pair<int, int> countZero() {
    int sum = 0;
    int maxVal = 0;
    for (int k = 0; k < height; ++k) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!a[k][i][j]) sum++;
                maxVal = max(a[k][i][j], maxVal);
            }
        }
    }


    return {sum, maxVal};
}



void bfs(vector<pair<int, pair<int, int>>>& sv) {

    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < sv.size(); ++i)
    {
        q.push({sv[i].first, {sv[i].second.first, sv[i].second.second}});
    }

    while (!q.empty()) {
        auto v = q.front();
        int hh = v.first;
        int rr = v.second.first;
        int cc = v.second.second;
        if (visited[hh][rr][cc]) continue;
        visited[hh][rr][cc] = true;
        q.pop();

        for (int i = 0; i < 6; ++i)
        {
            int nr = rr + dr[i];
            int nc = cc + dc[i];
            int nh = hh + dh[i];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || nh < 0 || nh >= height) {
                continue;
            }
            if (!visited[nh][nr][nc] && a[nh][nr][nc] != -1 && a[nh][nr][nc] != 1 && a[nh][nr][nc] == 0) {
                a[nh][nr][nc] = a[hh][rr][cc] + 1;
                q.push({nh, {nr, nc}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int, pair<int, int>>> sv;

    cin >> col >> row >> height;
    for (int k = 0; k < height; ++k)
    {
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j) {
                cin >> a[k][i][j];
                if (a[k][i][j] == 1) {
                    sv.push_back({k, {i, j}});
                }
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
