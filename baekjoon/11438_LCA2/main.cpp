#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1e9;
const int MAX = 100100;
int n, m, sz;

typedef pair<int, int> Node;    // depth, person

vector<int> child[MAX];
vector<Node> tree;
int visited[MAX];
int locInTree[MAX];

void update(int index, const Node &value) {
    index += (sz - 1);
    tree[index] = value;    // 한 번만 들어오니 assign도 상관 없음
    while (index > 1) {
        index /= 2;
        tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
    }
}

Node query(int node, int left, int right, int l, int r) {
    if (r < left || right < l) {
        return {INF, INF};
    }

    if (l <= left && right <= r) {
        return tree[node];
    }

    int mid = left + (right - left) / 2;
    return min(query(node * 2, left, mid, l, r), query(node * 2 + 1, mid + 1, right, l, r));
}

void dfs(int person, int depth) {
    static int cur = 1;

    int index = cur++;
    update(index, {depth, person});
    locInTree[person] = index;
    visited[person] = 1;

    for (int i = 0; i < child[person].size(); ++i) {
        if (visited[child[person][i]]) continue;
        dfs(child[person][i], depth + 1);
        update(cur++, {depth, person});
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    sz = 1 << (int) ceil(log2(2 * n));
    tree.resize(sz * 2, {INF, INF});

    int p, c;
    for (int i = 0; i < n - 1; ++i) {
        cin >> p >> c;
        child[p].push_back(c);
        child[c].push_back(p);
    }

    dfs(1, 0);

    cin >> m;
    int l, r;
    for (int j = 0; j < m; ++j) {
        cin >> l >> r;
        int ll = locInTree[l], rr = locInTree[r];
        if (ll > rr) swap(ll, rr);
        int answer = query(1, 1, sz, ll, rr).second;
        cout << answer << "\n";
    }

    return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//const int INF = 1e9;
//const int MAX = 100100;
//int n, m;
//
//vector<int> tree[MAX];
//int segmentTree[1 << 20];
//int traversed[1 << 20];
//int personToSerial[MAX];
//int serialToPerson[MAX];
//int visited[MAX];
//int locInTree[MAX];
//int serial = 1;
//int curr = 1;
//
//
//void dfs(int person) {
//    int mySerial = serial++;
//    personToSerial[person] = mySerial;
//    serialToPerson[mySerial] = person;
//    locInTree[person] = curr;
//    traversed[curr++] = mySerial;
//    visited[person] = 1;
//
//    for (int i = 0; i < tree[person].size(); ++i) {
//        if (visited[tree[person][i]]) {
//            continue;
//        }
//        dfs(tree[person][i]);
//        traversed[curr++] = mySerial;
//    }
//}
//
//void init(int node, int left, int right) {
//
//    if (left == right) {
//        segmentTree[node] = traversed[left];
//        return;
//    }
//
//    int mid = left + (right - left) / 2;
//    init(node * 2, left, mid);
//    init(node * 2 + 1, mid + 1, right);
//
//    segmentTree[node] = min(segmentTree[node * 2], segmentTree[node * 2 + 1]);
//}
//
//int query(int node, int left, int right, int l, int r) {
//    if (r < left || right < l) {
//        return INF;
//    }
//
//    if (l <= left && right <= r) {
//        return segmentTree[node];
//    }
//
//    int mid = left + (right - left) / 2;
//    return min(query(node * 2, left, mid, l, r), query(node * 2 + 1, mid + 1, right, l, r));
//}
//
//int main() {
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//
//    //freopen("in.txt", "r", stdin);
//
//    cin >> n;
//    int p, c;
//    for (int i = 0; i < n - 1; ++i) {
//        cin >> p >> c;
//        tree[p].push_back(c);
//        tree[c].push_back(p);
//    }
//
//    dfs(1);
//
//    init(1, 1, curr);
//
//    cin >> m;
//    int l, r;
//    for (int j = 0; j < m; ++j) {
//        cin >> l >> r;
//        int ll = locInTree[l];
//        int rr = locInTree[r];
//        if (ll > rr) swap(ll, rr);
//
//        int ancientSerial = query(1, 1, curr, ll, rr);
//        cout << serialToPerson[ancientSerial] << "\n";
//    }
//
//
//    return 0;
//}