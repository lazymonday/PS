#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 303000;
const int TREE_MAX = 1 << 20;
int n, c;

struct Node {
    Node() : color(0), freq(0) {}
    Node(int c, int f) : color{c}, freq{f} {}
    int color, freq;
};

Node tree[TREE_MAX];
Node empty;
vector<int> freq[10010];

Node merge(const Node& l, const Node& r) {
    // key idea : Kill the remaining pairs among L.count + R.count numbers that are left.
    if (l.color == r.color) {
        return {l.color, l.freq + r.freq};
    } else if (l.freq > r.freq) {
        return {l.color, l.freq - r.freq};
    }
    return {r.color, r.freq - l.freq};
}

void update(int node, int left, int right, int pos, const Node &value) {
    if (pos < left || right < pos) {
        return;
    }

    if (left == right) {
        tree[node] = value;
        return;
    }

    int mid = left + (right - left) / 2;
    update(node * 2, left, mid, pos, value);
    update(node * 2 + 1, mid + 1, right, pos, value);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int node, int left, int right, int start, int end) {
    if (end < left || right < start) {
        return empty;
    }

    if (start <= left && right <= end) {
        return tree[node];
    }

    int mid = left + (right - left) / 2;
    return merge(query(node * 2, left, mid, start, end), query(node * 2 + 1, mid + 1, right, start, end));
}


int getFreq(int color, int l, int r) {
    return upper_bound(freq[color].begin(), freq[color].end(), r) -
           lower_bound(freq[color].begin(), freq[color].end(), l);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    int color;

    for (int i = 1; i <= n; ++i) {
        cin >> color;
        freq[color].push_back(i);
        update(1, 1, n, i, {color, 1});
    }

    int m, l, r;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        int answer = query(1, 1, n, l, r).color;
        int frequency = 0;
        if (answer != 0) {
            frequency = getFreq(answer, l, r);
        }

        if (frequency > (r - l + 1) / 2) {
            cout << "yes " << answer << "\n";
        } else {
            cout << "no" << "\n";
        }
    }

    return 0;
}
