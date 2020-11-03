#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int n, t;
int balls[MAX + 1];


class BouncingBalls {
public:
    double expectedBounces(int a[], int T) {
        int len = n;
        const int MAX = 12;
        double ans = 0.0;

        sort(a, a + len);

        for (int i = 0; i < (1 << len); ++i)
        {
            int dir[MAX];
            for (int j = 0; j < len; ++j)
            {
                if ((i & (1 << j)) > 0) {
                    dir[j] = 1;
                } else {
                    dir[j] = -1;
                }
            }

            for (int l = 0; l < len; ++l)
            {
                for (int r = l + 1; r < len; ++r)
                {
                    if (dir[l] == 1 && dir[r] == -1 && a[r] - a[l] <= T * 2.0) ans += 1.0;
                }
            }
        }

        return ans / (double)(1 << len);

    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> balls[i];
    }

    cin >> t;
    BouncingBalls bb;
    cout << bb.expectedBounces(balls, t);


    return 0;
}
