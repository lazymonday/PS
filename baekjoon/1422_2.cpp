#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX = 1e3;
const int INF = 2e9;
typedef unsigned long long ll;

ll a[MAX + 1];

int main() {
    ll top = 0;
    int k, n;
    scanf("%d%d", &k, &n);
    for (int i = 0; i < k; ++i)
    {
        scanf("%llu", &a[i]);
        if (top < a[i]) {
            top = a[i];
        }
    }

    sort(a, a + k, [](const ll & a, const ll & b) {
        int a1 = floor(log10(a)) + 1;
        int b1 = floor(log10(b)) + 1;
        ll aa = a * pow(10, b1) + b;
        ll bb = b * pow(10, a1) + a;
        return aa > bb;
    });

    bool once = false;
    for (int i = 0; i < k; ++i)
    {
        printf("%llu", a[i]);
        if (a[i] == top && !once) {
            once = true;
            int t = n - k;
            while (t-- > 0) printf("%llu", top);
        }
    }

    return 0;
}
