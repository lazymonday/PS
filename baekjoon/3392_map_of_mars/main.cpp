#include <iostream>
#include <algorithm>

using namespace std;

struct line {
    short x, y1, y2, isStart;
};

const int MAX_N = 1e4;
line lines[2 * MAX_N];
pair<short, short> tree[1 << 16];
int n;

void update(int node, int left, int right, int l, int r, int dt) {
    if (r < left || right < l) {
        return;
    }

    if (l <= left && right <= r) {
        tree[node].second += dt;
    } else {
        int mid = left + (right - left) / 2;
        update(node * 2, left, mid, l, r, dt);
        update(node * 2 + 1, mid + 1, right, l, r, dt);
    }

    if (tree[node].second) {
        tree[node].first = right - left + 1;
    } else {
        if (left == right) {
            tree[node].first = 0;
        } else {
            tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    short x1, y1, x2, y2;
    for (int i = 0; i < n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        y1++; y2++;
        lines[i] = {x1, y1, y2, 1};
        lines[i + n] = {x2, y1, y2, -1};
    }

    sort(lines, lines + 2 * n, [](const line &l, const line &r) {
        return l.x < r.x;
    });

    int sz = 1 << 15;
    int ans = 0;
    for (int j = 0; j < 2 * n; ++j) {
        if (j > 0) {
            int dx = lines[j].x - lines[j - 1].x;
            int height = tree[1].first;
            ans += (dx * height);
        }
        update(1, 1, sz, lines[j].y1, lines[j].y2 - 1, lines[j].isStart);
    }

    cout << ans;

    return 0;
}
