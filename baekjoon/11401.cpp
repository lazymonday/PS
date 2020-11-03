#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

ll n, k;
int divisor = 1e9 + 7;

ll modPow(ll a, ll b) {
	if (b == 1) return a % divisor;
	if (b % 2 != 0) return a * modPow(a, b - 1) % divisor;
	ll t = modPow(a, b / 2);
	return (t * t) % divisor;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	ll x = 1;
	ll y = 1;
	for (int i = 0; i < k; ++i)
	{
		x = x * (n - i) % divisor;
		y = y * (i + 1) % divisor;
	}

	ll ans = (x * modPow(y, divisor - 2)) % divisor;
	if (ans < 0) {
		ans = (ans + divisor) % divisor;
	}
	cout << ans;

	return 0;
}
