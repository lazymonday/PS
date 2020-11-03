#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2e4;
const int INF = 2e9;
typedef long long ll;
int n;
int a[MAX + 1];
int front_ = 1e4;
int back_ = 1e4;
int size_ = 0;

int size() {
    return size_;
}

int front() {
    if (size_ == 0) return -1;
    return a[front_ + 1];
}

int back() {
    if (size_ == 0) return -1;
    return a[back_ - 1];
}

int empty() {
    return size_ == 0 ? 1 : 0;
}

void push_front(int num) {
    if (back_ == front_) {
        back_++;
    }

    a[front_--] = num;
    size_++;
}

void push_back(int num) {
    if (back_ == front_) {
        front_--;
    }
    a[back_++] = num;
    size_++;
}

int pop_front() {
    if (size_ == 0) return -1;
    int ret = a[++front_];
    if (--size_ == 0) {
        front_ = back_ = 1e4;
    }

    return ret;
}

int pop_back() {
    if (size_ == 0) return -1;
    int ret = a[--back_];
    if (--size_ == 0) {
        front_ = back_ = 1e4;
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
        int param;
        if (cmd == "push_front") {
            cin >> param;
            push_front(param);
        } else if (cmd == "push_back") {
            cin >> param;
            push_back(param);
        } else if (cmd == "pop_front") {
            cout << pop_front() << "\n";
        } else if (cmd == "pop_back") {
            cout << pop_back() << "\n";
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
