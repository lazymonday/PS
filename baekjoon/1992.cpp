#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 64;
const int INF = 2e9;
typedef long long ll;

int n;
char a[MAX + 1][MAX + 1];

void solve(int r, int c, int n) {

    if (n == 1) {
        printf("%c", (a[r][c] == '1' ? '1' : '0'));
        return;
    }

    int half = n / 2;

    bool isBlack = (a[r][c] == '1' ? true : false);
    bool needDivide = false;
    for (int i = r; i < r + n; ++i)
    {
        for (int j = c; j < c + n; ++j)
        {
            if ((isBlack && a[i][j] != '1') || (!isBlack && a[i][j] != '0')) {
                needDivide = true;
                break;
            }
        }

        if (needDivide) {
            break;
        }
    }

    if (needDivide) {
        printf("(");
        solve(r, c, half);
        solve(r, c + half, half);
        solve(r + half, c, half);
        solve(r + half, c + half, half);
        printf(")");
    } else {
        printf("%c", (isBlack ? '1' : '0'));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    solve(0, 0, n);

    return 0;
}
