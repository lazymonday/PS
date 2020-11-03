#include <bits/stdc++.h>

using namespace std;

const int MAXBASE = 15000;
int n;


inline int base10(int num, int k) {
    return (num / 100 * k * k) + ((num % 100) / 10 * k) + (num % 10);
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

        while (ba <= MAXBASE && bb <= MAXBASE) {
            ca = base10(a, ba);
            cb = base10(b, bb);
            if (ca < cb) {
                ba++;
            } else if (ca > cb) {
                bb++;
            } else {
                cout << ba << " " << bb << "\n";
                break;
            }
        }
    }

    return 0;
}
