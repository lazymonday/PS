#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 4e6;
const int INF = 2e9;
typedef long long ll;

ll mod = 1e9 + 7;

ll fact[MAX + 1];
ll inv[MAX + 1];

ll modPow(ll a, ll b) {
	if (b == 1) return a % mod;
	if (b % 2 != 0) return a * modPow(a, b - 1) % mod;
	ll t = modPow(a, b / 2) % mod;
	return t * t % mod;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, r;
	cin >> n >> r;

	fact[0] = fact[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		fact[i] = (fact[i - 1] * i) % mod;
	}

	inv[n] = modPow(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; --i)
	{
		inv[i] = (inv[i + 1] * (i + 1)) % mod;
	}

	cout << fact[n] * inv[n - r] % mod * inv[r] % mod;

	return 0;
}
