#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;

int n;
int a[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans = max(ans, a[i] * (n - i + 1));
	}

	cout << ans;

	return 0;
}
