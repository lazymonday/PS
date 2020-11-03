#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;


int np[MAX + 1];

void findPrime(int ub) {
    np[0] = np[1] = 1;
    int sz = sqrt(ub);
    for (int i = 2; i <= sz; ++i) {
        if (np[i] == 0) {
            for (int j = i * i; j <= ub; j += i) {
                np[j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int l, r;
    cin >> l >> r;

    findPrime(r);

    for (int i = l; i <= r; i++) {
        if (np[i] == 1) continue;
        cout << i << "\n";
    }

    return 0;
}
