#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2e4;
const int INF = 2e9;
typedef long long ll;
int n;
int a[MAX + 1];
int front_ = 0;
int back_ = 0;
int size_ = 0;

int size() {
    return size_;
}

int front() {
    if (size_ == 0) return -1;
    return a[front_];
}

int back() {
    if (size_ == 0) return -1;
    return a[back_ - 1];
}

int empty() {
    return size_ == 0 ? 1 : 0;
}

void push(int num) {
    a[back_++] = num;
    size_++;
}

int pop() {
    if (size_ == 0) return -1;
    int ret = a[front_++];
    if (--size_ == 0) {
        front_ = back_ = 0;
    }

    return ret;
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
        } else if (cmd == "front") {
            cout << front() << "\n";
        } else if (cmd == "back") {
            cout << back() << "\n";
        }
    }

    return 0;
}
