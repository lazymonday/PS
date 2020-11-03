#include <bits/stdc++.h>

using namespace std;

int n;

inline int base10(int num, int k) {
    return (num / 100 * k * k) + ((num % 100) / 10 * k) + (num % 10);
}

int findBase(int num, int origin) {
    int hi = 15000;
    int lo = 10;

    while (lo < hi) {
        int x = lo + (hi - lo) / 2;
        int guess = base10(num, x);
        if (guess < origin) {
            lo = x + 1;
        } else {
            hi = x;
        }
    }

    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;

        int ba = 10, bb = 10;
        int ca, cb;

        do {
            ca = base10(a, ba);
            cb = base10(b, bb);
            if (ca < cb) {
                ba = findBase(a, cb);
            } else {
                bb = findBase(b, ca);
            }
        } while (ca != cb);

        cout << ba << " " << bb << "\n";
    }

    return 0;
}
