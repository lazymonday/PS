#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

using namespace std;

static const int maxSize = 100000;

class UnionFind {
public:
    UnionFind(int max) {
        for (int i = 0; i <= max; ++i) {
            roots[i] = i;
            rank[i] = 0;
            count[i] = 1;
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
            count[q] += count[p];
            count[p] = 1;
        } else {
            roots[q] = p;
            count[p] += count[q];
            count[q] = 1;
            if (rank[p] == rank[q]) {
                rank[p]++;
            }
        }
    }

    int size(int p) {
        return count[find(p)];
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

private:
    int roots[maxSize];
    int rank[maxSize];
    int count[maxSize];
};

int n;

int main() {

    scanf("%d", &n);
    while(--n >= 0) {
        int f;
        scanf("%d", &f);
        UnionFind set(f);
        map<string, int> friendTbl;
        int serial = 0;
        for(int i = 0; i < f; ++i) {
            char fri1[21];
            char fri2[21];
            scanf("%s %s", fri1, fri2);
            string friend1(fri1);
            string friend2(fri2);
            int serial1, serial2;
            if(friendTbl.find(friend1) == friendTbl.end()) {
                serial1 = serial++;
                friendTbl.insert(std::make_pair(friend1, serial1));
            } else {
                serial1 = friendTbl.find(friend1)->second;
            }

            if(friendTbl.find(friend2) == friendTbl.end()) {
                serial2 = serial++;
                friendTbl.insert(std::make_pair(friend2, serial2));
            } else {
                serial2 = friendTbl.find(friend2)->second;
            }

            set.uni(serial1, serial2);
            printf("%d\n", set.size(serial1));
        }

    }

    return 0;
}
