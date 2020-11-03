#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int debug = 1;
int n, q;
struct Cmd {
    int begin;
    int end;
    int distance;     //
    bool isQuery;   // true = query, false = edge
    int no;
};
Cmd cmd[750000];
int cmdCount = 0;
int checkpoint[250001][2];
std::vector<pair<int/*x*/, int /*checkNo*/>> checkX;
std::vector<pair<int/*y*/, int /*checkNo*/>> checkY;

static const int maxSize = 250001;

class UnionFind {
public:
    UnionFind(int max_) : max(max_) {
        init();
    }

    void init() {
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
    int max;
    int roots[maxSize];
    unsigned char rank[maxSize];
};

UnionFind uf(250001);

int main() {

    if (debug) {
        n = 250000;
        q = 250000;
    } else {
        scanf("%d %d", &n, &q);
    }

    checkX.resize(n);
    checkY.resize(n);
    int x, y;
    for (int i = 0; i < n; ++i) {
        if (debug) {
            x = rand() % 2000000000 - 1000000000;
            y = rand() % 2000000000 - 1000000000;
        } else {
            scanf("%d %d", &x, &y);
        }

        checkX[i].first = x;
        checkX[i].second = i;
        checkY[i].first = y;
        checkY[i].second = i;
        checkpoint[i][0] = x;
        checkpoint[i][1] = y;
    }

    auto comp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.first < rhs.first;
    };

    sort(checkX.begin(), checkX.end(), comp);
    sort(checkY.begin(), checkY.end(), comp);

    for (int i = 1; i < n; ++i) {
        int diff = checkX[i].first - checkX[i - 1].first;
        cmd[cmdCount++] = {checkX[i].second, checkX[i - 1].second, diff, false, -1};
    }

    for (int i = 1; i < n; ++i) {
        int diff = checkY[i].first - checkY[i - 1].first;
        cmd[cmdCount++] = {checkY[i].second, checkY[i - 1].second, diff, false, -1};
    }

    for (int i = 0; i < q; ++i) {
        if (debug) {
            cmd[cmdCount] = {rand() % 250000, rand() % 250000, rand() % 1000000000, true, i};

        } else {
            scanf("%d %d %d", &cmd[cmdCount].begin, &cmd[cmdCount].end, &cmd[cmdCount].distance);
        }
        cmd[cmdCount].isQuery = true;
        cmd[cmdCount++].no = i;
    }

    sort(cmd, cmd + cmdCount, [](const Cmd &lhs, const Cmd &rhs) {
        if(lhs.distance < rhs.distance) {
            return true;
        } else if(lhs.distance > rhs.distance) {
            return false;
        }

        if(lhs.isQuery != rhs.isQuery) {
            if(!lhs.isQuery) {
                return true;
            } else if(!rhs.isQuery) {
                return false;
            }
        }

        return false;
    });

    bool result[250000];
    for (int i = 0; i < cmdCount; ++i) {
        if(cmd[i].isQuery) {
            result[cmd[i].no] = uf.isConnected(cmd[i].begin-1, cmd[i].end-1);
        } else {
            uf.uni(cmd[i].begin, cmd[i].end);
        }
    }

    for (int i = 0; i < q; ++i) {
        if (result[i]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
