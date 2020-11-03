#include <iostream>
#include <stack>

using namespace std;
const int MAX = 3e5;
int n;

struct circle {
    int r, x;

    inline int left() { return x - r; }

    inline int right() { return x + r; }
};

circle circles[MAX + 1];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> circles[i].x >> circles[i].r;
    }

    sort(circles, circles + n, [](const circle &l, const circle &r) {
        if (l.x - l.r != r.x - r.r) return l.x - l.r < r.x - r.r;
        return l.r > r.r;
    });

    circles[n].x = 2e9;
    circles[n].r = 1;
    n++;

    int ans = n;
    stack<int> s;
    s.push(0);
    int j = 1;
    while (!s.empty() && j < n) {
        if (s.size() > 0) {
            int top = s.top();
            if (circles[top].right() <= circles[j].left()) {
                int right = circles[top].right();
                s.pop();
                while (circles[s.top()].right() < right) {
                    top = s.top();
                    if (circles[top].right() == right) {
                        ans++;
                    }
                    s.pop();
                }

                if (circles[top].right() == circles[j].left()) {
                    s.push(top);
                } else {
                    if (!s.empty()) {
                        s.pop();
                    }
                }
            }
        }

        if (j < n - 1) {
            s.push(j++);
        }
    }

    cout << ans;

    return 0;
}
