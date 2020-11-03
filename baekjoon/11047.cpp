#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10;
const int INF = 2e9;
typedef long long ll;

int n, k;
int coin[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> coin[i];
	}

	sort(coin, coin + n, [](const int& a, const int& b) {
		return a > b;
	});

	int cur = k;
	int ans = 0;
	int ci = 0;
	while (cur > 0) {
		ans += cur / coin[ci];
		cur = cur % coin[ci];
		ci++;
	}

	cout << ans;

	return 0;
}
