#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int solve(string s) {
    int len = s.size();
    if (len % 2 == 0 || len == 1) {
        return 1;
    }

    int half = len / 2;
    int ret = 1;

    // ABC -> AB + ABC
    if (s.substr(0, half) == s.substr(half, half)) {
        ret += solve(s.substr(half));
    }

    // ABC -> ABC + AB
    if (s.substr(0, half) == s.substr(half + 1)) {
        ret += solve(s.substr(0, half + 1));
    }

    // ABC -> BC + ABC
    if (s.substr(0, half) == s.substr(half + 1)) {
        ret += solve(s.substr(half));
    }

    // ABC -> ABC + BC
    if (s.substr(half + 1) == s.substr(1, half)) {
        ret += solve(s.substr(0, half + 1));
    }

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    cout << solve(s) - 1;

    return 0;
}
