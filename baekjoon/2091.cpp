#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int p;
int coin[4];
int worth[4] = {1, 5, 10, 25};
int ans[4];

int solve(int price, int index) {

	if(price == 0) return 0;

	if (index == 4) {
		return 0;
	}
	
	int ret = 0;
	int cnt = min(coin[index], price / worth[index]);

	for (int i = cnt; i >= 0; --i)
	{
		ans[index] = i;
		ret = max(ret, solve(price - i * worth[index], index + 1));
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> p;
	for (int i = 0; i < 4; ++i)	{
		cin >> coin[i];
	}

	return 0;
}
