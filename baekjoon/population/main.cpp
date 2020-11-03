#include <iostream>

using namespace std;

static const int maxSize = 2500;

class UnionFind {
public:
    UnionFind() {
        for (int i = 0; i < maxSize; ++i) {
            roots[i] = i;
            nodeCounts[i] = 1;
        }
    }

    int find(int n) {
        if (roots[n] == n) {
            return n;
        }

        return roots[n] = find(roots[n]);
    }

    int uni(int p, int q) {
        p = find(p);
        q = find(q);

        if (p == q) {
            return -1;
        }

        roots[q] = p;
        nodeCounts[p] += nodeCounts[q];
        nodeCounts[q] = 1;
        return nodeCounts[p];
    }

    int counts(int n) {
        return nodeCounts[find(n)];
    }

private:
    int roots[maxSize];
    int nodeCounts[maxSize];

};

int n, l, r;
int pop[maxSize];


int move() {
    // r, c
    int dir[4][2] = {{0,  1},   // right
                     {1,  0},   // down
                     {0,  -1},  // left
                     {-1, 0}};  // up


    UnionFind unionFind;
    int moves = 0;
    int sum[maxSize];
    int nn = n * n;
    for (int i = 0; i < nn; ++i) {
        sum[i] = pop[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int srcPop = pop[i * n + j];
            for (int k = 0; k < 4; ++k) {
                int adj_r = i + dir[k][0];
                int adj_c = j + dir[k][1];
                if (adj_r < 0 || adj_r >= n ||
                    adj_c < 0 || adj_c >= n) {
                    continue;
                }

                int dstPop = pop[adj_r * n + adj_c];
                int diff = abs(srcPop - dstPop);
                if (diff >= l && diff <= r) {
                    int p = unionFind.find(i * n + j);
                    int q = unionFind.find(adj_r * n + adj_c);
                    int ret = unionFind.uni(i * n + j, adj_r * n + adj_c);
                    if (ret > 0) {
                        sum[p] += sum[q];
                    }
                }
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int counts = unionFind.counts(i * n + j);
            if (counts >= 2) {
                int numOfPop = sum[unionFind.find(i * n + j)];
                int newPop = numOfPop / counts;
                if (numOfPop != newPop) {
                    ++moves;
                    pop[i * n + j] = newPop;
                }
            }
        }
    }

    return moves;
}


int main() {

    cin >> n >> l >> r;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> pop[i * n + j];
        }
    }

    int maxN = 2000;
    int i = 0;
    while (move() != 0 && ++i < maxN) {};
    cout << i << endl;

    return 0;
}
