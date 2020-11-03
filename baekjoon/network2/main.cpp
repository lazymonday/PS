#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static const int maxSize = 100001;

int n, m;
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
    int roots[maxSize];
    int rank[maxSize];
};

int kruskal() {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0; i < edges.size(); ++i) {
        pq.push({edges[i].first, i});
    }

    UnionFind uf(100001);

    int total = 0;
    int mstSize = 0;
    while(!pq.empty() && mstSize < n) {
        auto edge = pq.top();
        pq.pop();
        int u = edges[edge.second].second.first;
        int v = edges[edge.second].second.second;

        if(!uf.isConnected(u, v)) {
            total += edge.first;
            uf.uni(u, v);
            // add to mst
            ++mstSize;
        }
    }

    return total;
}


int main() {
    cin >> n >> m;

    edges.resize(m+1);
    int s, t, cost;
    for (int i = 1; i <= m; ++i) {
        cin >> s >> t >> cost;
        edges[i] = {cost, {s, t}};
    }

    cout << kruskal() << endl;

    return 0;
}
