#include <iostream>

const int divisor = 1e6;

using namespace std;

int cache[1001][3][4];

int attend(int remain, int late, int absent, bool lastAbsent) {

    absent = lastAbsent ? ++absent : 0;

//    for (int i = 0; i < remain; ++i) {
//        printf(" ");
//    }
//    printf("(%d, %d, %d)\n", remain, late, absent);

    int &ret = cache[remain][late][absent];
    if (ret != -1) {
        return ret;
    }

    if (late == 2 || absent == 3) {
        return 0;
    }

    if (remain == 0) {
        return 1;
    }

    if (remain < 0) {
        return 0;
    }

    ret = ((attend(remain - 1, late, absent, false) % divisor)
           + (attend(remain - 1, late + 1, absent, false) % divisor)
           + (attend(remain - 1, late, absent, true) % divisor)) % divisor;

    return ret;
}

int attend2(int days) {

    int dp[1001][2][3] = {0};

    dp[0][0][0] = 1;

    for (int d = 1; d <= days; ++d) {
        for (int late = 0; late < 2; ++late) {
            for (int ab = 0; ab < 3; ++ab) {
                // attend
                // 전날 결석, 출석, 지각 모두 가능
                dp[d][late][0] += dp[d - 1][late][ab];
                dp[d][late][0] %= divisor;

                // late
                if (late == 0) {
                    // 지각은 X, 전날 한 결석한 횟수 만큼씩 더해지면 된다.
                    dp[d][late + 1][0] += dp[d - 1][late][ab];
                    dp[d][late + 1][0] %= divisor;
                }

                // absent
                if (ab < 2) {
                    // 전 날 결석한 횟수만큼 경우의 수가 늘어남.
                    dp[d][late][ab + 1] = dp[d - 1][late][ab] % divisor;
                }
            }
        }
    }

    int total = 0;
    for (int l = 0; l < 2; ++l) {
        for (int j = 0; j < 3; ++j) {
            total += dp[days][l][j];
            total %= divisor;
        }
    }

    return total;
}

int main() {

    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 4; ++k) {
                cache[i][j][k] = -1;
            }
        }
    }

    int n;
    cin >> n;
    cout << attend2(n) << '\n';
    return 0;
}
