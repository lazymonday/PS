#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int, int> Seg;
const int MAX = 1e5;
int n;
Seg pts[MAX + 1];

inline ll ccw(const Seg &origin, const Seg &a, const Seg &b) {
    Seg first = {a.first - origin.first, a.second - origin.second};
    Seg second = {b.first - origin.first, b.second - origin.second};

    return 1ll * first.first * second.second - 1ll * first.second * second.first;
}

bool cmp(const Seg &a, const Seg &b) {
    auto ret = ccw(pts[0], a, b);
    if (ret == 0) {
        return a < b;
    }

    return ret > 0;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        pts[i] = {x, y};
    }

    swap(pts[0], *min_element(pts, pts + n));
    sort(pts + 1, pts + n, cmp);

    stack<int> ch;
    int next = 0;

    while (next < n) {
        while (ch.size() >= 2) {
            auto sec = ch.top();
            ch.pop();
            if (ccw(pts[sec], pts[next], pts[ch.top()]) > 0ll) {
                ch.push(sec);
                break;
            }
        }

        ch.push(next++);
    }

    cout << ch.size();

    return 0;
}
