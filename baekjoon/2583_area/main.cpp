#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100;
const int INF = 2e9;
typedef long long ll;

int row, col, k;
int board[MAX + 1][MAX + 1];
int visited[MAX + 1][MAX + 1];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void fillBoard(int x1, int y1, int x2, int y2) {
    for (int i = x1; i < x2; ++i) {
        for (int j = y1; j < y2; ++j) {
            board[j][i] = 1;
        }
    }
}


int dfs(int r, int c) {
    visited[r][c] = 1;
    int area = 1;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
            continue;
        }

        if (board[nr][nc] == 1 || visited[nr][nc]) {
            continue;
        }
        area += dfs(nr, nc);
    }

    return area;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> row >> col >> k;
    for (int i = 0; i < k; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        fillBoard(x1, y1, x2, y2);
    }

    vector<int> area;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (board[i][j] == 1 || visited[i][j]) continue;
            int ret = dfs(i, j);
            if (ret) {
                area.push_back(ret);
            }
        }
    }

    sort(area.begin(), area.end());

    cout << area.size() << "\n";
    for (auto ar : area) {
        cout << ar << " ";
    }

    return 0;
}
