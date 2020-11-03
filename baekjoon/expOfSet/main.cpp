//#include <iostream>
#include <stdio.h>

using namespace std;

static const int maxSize = 1000001;

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

int n, m;

int main() {

//    cout.sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    scanf("%d %d", &n, &m);
    //cin >> n >> m;
    UnionFind set(n);
    int ops, lhs, rhs;
    for (int i = 0; i < m; ++i) {
        //cin >> ops >> lhs >> rhs;
        scanf("%d %d %d", &ops, &lhs, &rhs);
        if (ops == 0) {
            set.uni(lhs, rhs);
        } else if (ops == 1) {
            //cout <<  << endl;
            printf("%s\n", (set.isConnected(lhs, rhs) ? "YES" : "NO"));
        }
    }

    return 0;
}
