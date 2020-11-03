#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;

int n;
int st[MAX + 1];
int cnt = 0;
int ans[MAX * 2 + 2];
int ansCnt = 0;

inline void push(int num) {
    st[cnt++] = num;
    ans[ansCnt++] = 1;
}

inline int top() {
    if (cnt == 0) return 0;
    return st[cnt - 1];
}

inline int pop() {
    if (cnt == 0) return 0;
    ans[ansCnt++] = -1;
    return st[--cnt];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int last = 0;
    int t;
    while (n--) {
        cin >> t;
        if (last < t) {
            for (int i = last + 1; i <= t; ++i) {
                last = i;
                push(i);
            }
            pop();
        } else if (top() == t) {
            pop();
        } else {
            cout << "NO";
            return 0;
        }
    }

    for (int j = 0; j < ansCnt; ++j) {
        cout << (ans[j] == 1 ? "+\n" : "-\n");
    }

    return 0;
}
