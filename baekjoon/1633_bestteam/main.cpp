#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int score[1000][2];
int cache[1000][16][16];

int makeTeam2(int nth, int w, int b) {

    if (w == 0 && b == 0) {
        return 0;
    }

    if (nth < 0) {
        return -1;
    }

    int &ret = cache[nth][w][b];
    if (ret != -1) {
        return ret;
    }

    ret = makeTeam2(nth - 1, w, b);
    if (w > 0) {
        ret = max(ret, makeTeam2(nth - 1, w - 1, b) + score[nth][0]);
    }
    if (b > 0) {
        ret = max(ret, makeTeam2(nth - 1, w, b - 1) + score[nth][1]);
    }

    return ret;

}

int main2() {

    int count = 0;

    while (scanf("%d %d", &score[count][0], &score[count][1]) == 2) ++count;

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 16; ++j) {
            for (int k = 0; k < 16; ++k) {
                cache[i][j][k] = -1;
            }
        }
    }

    printf("%d\n", makeTeam2(count - 1, 15, 15));
    return 0;
}

const int MAX = 1000;
int dp[16][16];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int w, b;
    while (cin >> w >> b) {
        for (int i = 15; i >= 0; --i) {
            for (int j = 15; j >= 0; --j) {
                dp[i][j] = max(dp[i][j], max((i ? dp[i - 1][j] + w : 0), (j ? dp[i][j - 1] + b : 0)));
            }
        }
    }

    cout << dp[15][15];

    return 0;
}