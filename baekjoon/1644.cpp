#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 4e6;
const int INF = 2e9;
typedef long long ll;

int notp[MAX + 1];
int prime[300000];

int sieve(int maxn) {

	notp[0] = notp[1] = 1;
	for (int i = 2; i * i <= maxn; ++i)
	{
		if (notp[i]) continue;
		for (int j = i * i; j <= maxn; j += i)
			notp[j] = 1;
	}

	int cur = 0;
	prime[cur++] = 2;
	for (int i = 3; i <= maxn; i += 2)
	{
		if (notp[i]) continue;
		prime[cur++] = i;
	}

	return cur;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int pn = sieve(n);

	int sum = 0, cnt = 0;
	int l = 0, r = 0;
	while (r <= pn)
	{
		if (sum < n) {
			sum += prime[r++];
		} else if (sum > n) {
			sum -= prime[l++];
		} else {
			cnt++;
			sum += prime[r++];
		}
	}

	cout << cnt;

	return 0;
}
