#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 15;
const int INF = 2e9;
typedef long long ll;

int n;
int nqueen[MAX];

int nq(int row) {
    if (row == n) {
        return 1;
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < row; ++j) {
            if (nqueen[j] == i || abs(row - j) == abs(i - nqueen[j])) {
                ok = false;
                break;
            }
        }

        if (ok) {
            nqueen[row] = i;
            ret += nq(row + 1);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cout << nq(0);
    return 0;
}