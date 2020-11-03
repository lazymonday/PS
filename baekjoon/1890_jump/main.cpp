#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 100;
int board[MAX][MAX];
ll dp[MAX * MAX + 1];
int dr[] = {0, 1};
int dc[] = {1, 0};
int n;

ll count() {

    dp[0] = 1;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (board[r][c] == 0) {
                break;
            }

            for (int k = 0; k < 2; ++k) {
                int nr = r + dr[k] * board[r][c];
                int nc = c + dc[k] * board[r][c];
                if (nr >= n || nc >= n) {
                    continue;
                }

                dp[nr * n + nc] += dp[r * n + c];
            }
        }
    }

    return dp[n * n - 1];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    cout << count() << "\n";

    return 0;
}
