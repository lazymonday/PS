#include <vector>
#include <stdio.h>

using namespace std;

typedef long long ll;

const int MAX = 1000001;
int n, m, k;
vector<ll> nums;

void add(int pos, ll value) {
    while (pos <= n) {
        nums[pos] += value;
        pos += (pos & -pos);
    }
}

ll sum(int pos) {
    ll ret = 0;
    while (pos > 0) {
        ret += nums[pos];
        pos &= (pos - 1);
    }

    return ret;
}

int main() {

    scanf("%d %d %d", &n, &m, &k);

    nums.resize(n + 1, 0);
    vector<ll> input(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &input[i]);
        add(i, input[i]);
    }

    ll a, b, c;
    for (int j = 0; j < k + m; ++j) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) {
            add(b, c - input[b]);
            input[b] = c;
        } else {
            printf("%lld\n", sum(c) - (b > 1 ? sum(b - 1) : 0));
        }
    }

    return 0;
}
