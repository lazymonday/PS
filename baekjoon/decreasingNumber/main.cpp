#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
queue<ll> q;

ll find(int kth) {

    if (kth < 10) {
        return kth;
    }

    for (int i = 0; i < 10; ++i) {
        q.push(i);
    }

    int index = 0;
    ll cur = 0;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (kth == index) {
            return cur;
        }

        for (int j = 0; j < cur % 10; ++j) {
            q.push(cur * 10 + j);
        }

        ++index;
    }

    return -1;
}

void make_decrease_array(int kth) {
    kth = max(1022, kth);
    ll ans[1023] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};
    int last = 10;
    for (int cur = 0; cur < kth; ++cur) {
        for (int i = 0; i < ans[cur] % 10; ++i) {
            ans[last++] = ans[cur] * 10 + i;
        }
    }

    for (int j = 0; j < kth; ++j) {
        cout << ans[j] << endl;
    }
}

int dp[10][11]; // digit, len

void recon(int start, int len, int kth) {

    cout << start;
    if (len <= 1) {
        return;
    }

    for (int i = 0; i < start; ++i) {
        if (kth <= dp[i][len - 1]) {
            recon(i, len - 1, kth);
            return;
        }

        kth -= dp[i][len - 1];
    }
}

void solve(int kth) {

    if (kth < 10) {
        cout << kth;
        return;
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 11; ++j) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < 10; ++i) {
        dp[i][1] = 1;
    }

    kth -= 9;
    for (int len = 2; len <= 10; ++len) {
        for (int start_digit = 1; start_digit < 10; ++start_digit) {
            for (int k = 0; k < start_digit; ++k) {
                dp[start_digit][len] += dp[k][len - 1];
            }

            if (dp[start_digit][len] >= kth) {
                return recon(start_digit, len, kth);
            }

            kth -= dp[start_digit][len];
        }
    }

    cout << "-1" << endl;
}

int main() {

    int kth;

    cin >> kth;

    //cout << find(kth) << endl;
    //make_decrease_array(kth);
    solve(kth);
    cout << endl;
    return 0;
}
