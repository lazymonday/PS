#include <iostream>
#include <vector>

using namespace std;

vector<char> balls;

bool lt(int a, int b) {
    cout << "? " << balls[a] << " " << balls[b] << endl;
    char c;
    cin >> c;
    return c == '<';
}

bool less_than(char a, char b) {
    cout << "? " << a << " " << b << endl;
    char c;
    cin >> c;
    return c == '<';
}

void swap(int a, int b) {
    char t = balls[a];
    balls[a] = balls[b];
    balls[b] = t;
}

void merge(int begin, int mid, int end) {
    vector<char> tmp(balls);
    int p1 = begin;
    int p2 = mid + 1;
    int cur = begin;

    while (p1 <= mid) {
        if (p2 > end) {
            balls[cur++] = tmp[p1++];
            continue;
        }

        if (less_than(tmp[p1], tmp[p2])) {
            balls[cur++] = tmp[p1++];
        } else {
            balls[cur++] = tmp[p2++];
        }
    }
}

void mergeSort(int begin, int end) {
    if (begin >= end) {
        return;
    }

    int mid = begin + (end - begin) / 2;

    mergeSort(begin, mid);
    mergeSort(mid + 1, end);

    merge(begin, mid, end);
}

void solve(int n, int q) {
    if (n == 5 && q == 7) {
        if (!lt(0, 1)) {
            swap(0, 1);
        }

        if (!lt(2, 3)) {
            swap(2, 3);
        }

        if (!lt(1, 3)) {
            swap(0, 2);
            swap(1, 3);
        }

        vector<char> answer;
        answer.push_back(balls[0]);
        answer.push_back(balls[1]);
        answer.push_back(balls[3]);

        // insert e into A < B < D
        char e = balls[4];
        if (less_than(e, answer[1])) {
            if (less_than(e, answer[0])) {
                answer.insert(answer.begin(), e);
            } else {
                answer.insert(answer.begin() + 1, e);
            }
        } else {
            if (less_than(e, answer[2])) {
                answer.insert(answer.begin() + 2, e);
            } else {
                answer.push_back(e);
            }
        }

        // insert c into first three elements
        char c = balls[2];
        if (less_than(c, answer[1])) {
            if (less_than(c, answer[0])) {
                answer.insert(answer.begin(), c);
            } else {
                answer.insert(answer.begin() + 1, c);
            }
        } else {
            if (less_than(c, answer[2])) {
                answer.insert(answer.begin() + 2, c);
            } else {
                answer.insert(answer.begin() + 3, c);
            }
        }

        balls.assign(answer.begin(), answer.end());

    } else {
        mergeSort(0, balls.size() - 1);
    }

}

int main() {

    int n, q;
    cin >> n >> q;

    balls.resize(n);
    for (int i = 0; i < n; ++i) {
        balls[i] = 'A' + i;
    }

    solve(n, q);
    cout << "! ";
    for (int j = 0; j < balls.size(); ++j) {
        cout << balls[j];
    }

    cout << endl;

    return 0;
}
