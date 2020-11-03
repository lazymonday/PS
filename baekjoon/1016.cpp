#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

ll l, r;
int p[MAX + 1];

void findPrime(int ub) {
	int sz = sqrt(ub);
	for (int i = 2; i <= sz; ++i)
	{
		if (p[i] == 0) {
			for (int j = i * i; j < ub; j += i)
			{
				p[j] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> l >> r;


	return 0;
}
