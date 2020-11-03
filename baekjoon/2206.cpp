#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000;
const int INF = 1e9;
typedef long long ll;

int row, col;
char a[MAX + 2][MAX + 2];
int dr[] = { -1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int visited[MAX * MAX + 1][2];

int bfs(int start) {

    int dest = row * col - 1;
    queue<pair<int, int>> q;
    q.push({start, 0});    // here, drilled

    if(start == dest) {
        return 1;
    }

    int dist = 1;
    while (!q.empty()) {

        int qsz = q.size();
        for (int k = 0; k < qsz; ++k)
        {
            auto here = q.front().first;
            auto drilled = q.front().second;

            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nr = here / col + dr[i];
                int nc = here % col + dc[i];
                int next = nr * col + nc;

                if (visited[next][drilled] || nr < 0 || nr >= row || nc < 0 || nc >= col) continue;

                if (next == dest) {
                    return dist + 1;
                }

                if (a[nr][nc] == 1 && drilled == 0) {
                    visited[next][1] = true;
                    q.push({next, 1});
                } else if (a[nr][nc] == 0 && drilled <= 1) {
                    visited[next][drilled] = true;
                    q.push({next, drilled});
                }
            }
        }

        dist++;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> row >> col;
    for (int i = 0; i < row; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            a[i][j] -= '0';
        }
    }

    cout << bfs(0);

    return 0;
}
