#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2e5;
typedef pair<int, pair<int, int>> vert;
int n, m;

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
};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<vert> edges(m);  // cost, to
        long long allCost = 0;
        int x, y, z;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> z;
            edges[i].first = z;
            edges[i].second.first = x;
            edges[i].second.second = y;
            allCost += edges[i].first;
        }

        sort(edges.begin(), edges.end(), [](const vert &a, const vert &b) {
            return a.first < b.first;
        });

        UnionFind uni(n + 1);
        long long mstCost = 0;
        int mstCnt = 0;
        for (int j = 0; j < m; ++j) {
            int u = edges[j].second.first;
            int v = edges[j].second.second;

            if (!uni.isConnected(u, v)) {
                uni.uni(u, v);
                mstCost += edges[j].first;
                if (++mstCnt == n - 1) {
                    break;
                }
            }
        }

        cout << allCost - mstCost << "\n";
    }

    return 0;
}
