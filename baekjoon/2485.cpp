#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

int n;
int a[MAX + 1];

int calc(ll x) {
	int cnt = 0;
	for (int j = 1; j < n; ++j)
	{
		ll diff = a[j] - a[j - 1];
		cout << "diff : " <<  diff <<  ", x : " << x << "\n";
		if (diff < x || diff % x != 0) {
			return false;
		}

		cnt += ((double)diff / x) - 1;
	}

	return cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	ll lo = 1;
	ll hi = 1e8;

	cout << "ret 2 : " << calc(2) << "\n";
	cout << "ret 3 : " << calc(3) << "\n";
	cout << "ret 1 : " << calc(1) << "\n";

	int minCount = INF;
	while (lo + 1 < hi) {
		ll x = lo + (hi - lo) / 2;
		auto count = calc(x);
		if (count != INF) {
			hi = x;
		} else {
			lo = x;
		}

		minCount = min(minCount, count);
	}

	cout << minCount << ", " << hi << ", " << lo;

	return 0;
}
