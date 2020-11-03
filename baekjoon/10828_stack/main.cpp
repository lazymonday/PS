#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e4;
const int INF = 2e9;
typedef long long ll;
int n;
int a[MAX + 1];
int top_ = 0;

int size() {
    return top_;
}

int top() {
    if (top_ == 0) return -1;
    return a[top_ - 1];
}

int empty() {
    return top_ == 0 ? 1 : 0;
}

void push(int num) {
    a[top_++] = num;
}

int pop() {
    if (top_ == 0) return -1;
    return a[--top_];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while (n--) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int param;
            cin >> param;
            push(param);
        } else if (cmd == "pop") {
            cout << pop() << "\n";
        } else if (cmd == "size") {
            cout << size() << "\n";
        } else if (cmd == "empty") {
            cout << empty() << "\n";
        } else if (cmd == "top") {
            cout << top() << "\n";
        }
    }

    return 0;
}
