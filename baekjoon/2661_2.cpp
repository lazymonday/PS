#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
typedef long long ll;

int N;
vector<int> a;

bool solve(int num) {
    if (a.size() == N) {
        for (auto x : a) cout << x;
        return true;
    }

    a.push_back(num);

    int half = a.size() / 2;
    int right = a.size() - 1;
    bool good = true;
    for (int len = 1; len <= half; ++len)
    {
        bool same = true;
        for (int i = 0; i < len; ++i) {
            if (a[right - len - i] != a[right - i]) {
                same = false;
                break;
            }
        }

        if (same) {
            good = false;
            break;
        }
    }

    bool ret = false;
    if (good) {
        for (int i = 1; i <= 3; ++i) {
            if (i == num) continue;
            ret = solve(i);
            if (ret) break;
        }
    }
    a.pop_back();
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    solve(1);
    return 0;
}
