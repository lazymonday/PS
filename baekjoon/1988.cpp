#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 3000;
const int INF = 2e9;
typedef long long ll;

int n, m;
int a[MAX + 1];
int dp[MAX + 1][MAX + 1][2];

int solve(int tried, int choose, int consec) {
	if (choose == m) return 0;
	if (tried == n) return -INF;

	auto& ret = dp[tried][choose][consec];
	if (ret != -1) return ret;

	ret = max(solve(tried + 1, choose, 0), solve(tried + 1, choose + 1, 1) + (consec ? a[tried] : 0));
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	memset(dp, -1, sizeof dp);
	cout << solve(0, 0, 0);

	return 0;
}
