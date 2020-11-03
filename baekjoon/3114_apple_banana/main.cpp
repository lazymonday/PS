#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1500;
int dp[MAX + 1][MAX + 1];
int sa[MAX + 1][MAX + 1];
int sb[MAX + 1][MAX + 1];
int row, col;


int main() {

    scanf("%d%d", &row, &col);
    char line[6100];
    fgets(line, 6100, stdin);
    for (int i = 1; i <= row; ++i) {
        fgets(line, 6100, stdin);
        int len = strlen(line);
        int col = 1, count = 0;
        bool isA = true;
        for (int k = 0; k < len; ++k) {
            if (line[k] == 'B') {
                isA = false;
            } else if (line[k] == ' ' || line[k] == '\n') {
                (isA ? sa[i][col] : sb[i][col]) = count;
                col++;
                count = 0;
                isA = true;
            } else if (line[k] >= '0' && line[k] <= '9') {
                count *= 10;
                count += line[k] - '0';
            }
        }
    }

    for (int rr = 1; rr <= row; ++rr) {
        for (int cc = 2; cc <= col; ++cc) {
            sa[rr][cc] += sa[rr][cc - 1];
            sb[rr][col - cc + 1] += sb[rr][col - cc + 2];
        }
    }

    for (int k = 1; k <= col; ++k) {
        dp[1][k] = sb[1][k + 1];
    }

    for (int r = 2; r <= row; ++r) {
        for (int c = 1; c <= col; ++c) {
            dp[r][c] = max(dp[r - 1][c - 1], dp[r - 1][c]) + sa[r][c - 1] + sb[r][c + 1];
            dp[r][c] = max(dp[r][c], dp[r][c - 1] + sb[r][c + 1] - sb[r][c]);
        }
    }

    printf("%d\n", dp[row][col]);

    return 0;
}
