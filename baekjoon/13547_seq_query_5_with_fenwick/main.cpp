#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Query {
    int e, s, i;

    bool operator<(const Query &rhs) const { return e < rhs.e; }
};

const int MAX = 100100;
int n, m;
int nums[MAX];
int answer[MAX];
int last[1001000];
vector<int> tree;
vector<Query> queries;

void add(int p, int val) {
    while (p < tree.size()) {
        tree[p] += val;
        p += (p & -p);
    }
}

int sum(int p) {
    int ret = 0;
    while (p > 0) {
        ret += tree[p];
        p -= (p & -p);
    }

    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    tree.resize(n + 1);

    cin >> m;
    queries.resize(m);
    for (int j = 0; j < m; ++j) {
        queries[j].i = j;
        cin >> queries[j].s >> queries[j].e;
    }

    sort(queries.begin(), queries.end());

    int pos = 1;
    for (int k = 0; k < m; ++k) {
        while (pos <= queries[k].e) {
            if (last[nums[pos]]) {
                add(last[nums[pos]], -1);
            }

            add((last[nums[pos]] = pos), 1);
            pos++;
        }

        answer[queries[k].i] = sum(queries[k].e) - sum(queries[k].s - 1);
    }

    for (int l = 0; l < m; ++l) {
        cout << answer[l] << "\n";
    }

    return 0;
}
