#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAX = 100;
int board[MAX + 1][MAX + 1];
int num[MAX + 1][MAX + 1];
int row, col;
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
vector<pair<int, pair<int, int>>> edges;

class UnionFind {
public:
    UnionFind(int max) {
        for (int i = 0; i <= max; ++i) {
            roots[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        int p = roots[x];
        while (p != roots[p]) {
            roots[p] = roots[roots[p]];
            p = roots[p];
        }

        return p;
    }

    void uni(int p, int q) {
        p = find(p);
        q = find(q);

        if (p == q) {
            return;
        }

        if (rank[p] < rank[q]) {
            roots[p] = q;
        } else {
            roots[q] = p;
            if (rank[p] == rank[q]) {
                rank[p]++;
            }
        }
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

private:
    int roots[MAX + 1];
    int rank[MAX + 1];
} uf(100);

bool dfs(int r, int c, int group) {
    if (num[r][c]) {
        return false;
    }

    num[r][c] = group;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
            continue;
        }

        if (board[nr][nc] != 0) {
            dfs(nr, nc, group);
        }
    }

    return true;
}

int numbering() {
    int group = 1;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (board[r][c] == 1) {
                if (dfs(r, c, group)) group++;
            }
        }
    }

    return group - 1;
}

void make_edges() {
    for (int i = 0; i < row; ++i) {
        int space = 0;
        int last = 0;
        for (int j = 0; j < col; ++j) {
            if (num[i][j] != 0) {
                if (last != 0 && last != num[i][j] && space >= 2) {
                    edges.push_back({space, {last, num[i][j]}});
                }
                last = num[i][j];
                space = 0;
            } else {
                space++;
            }
        }
    }

    for (int j = 0; j < col; ++j) {
        int space = 0, last = 0;
        for (int i = 0; i < row; ++i) {
            if (num[i][j] != 0) {
                if (last != 0 && last != num[i][j] && space >= 2) {
                    edges.push_back({space, {last, num[i][j]}});
                }
                last = num[i][j];
                space = 0;
            } else {
                space++;
            }
        }
    }

    sort(edges.begin(), edges.end(), [](auto &lhs, auto &rhs) {
        return lhs.first < rhs.first;
    });
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> row >> col;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            cin >> board[r][c];
        }
    }

    int landCount = numbering();
    make_edges();

    int mstCount = 0;
    int mstSize = 0;
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if (!uf.isConnected(u, v)) {
            uf.uni(u, v);
            mstSize += edges[i].first;
            if (++mstCount == landCount - 1) {
                break;
            }
        }
    }

    if (mstCount != landCount - 1) {
        cout << -1;
    } else {
        cout << mstSize;
    }

    return 0;
}
