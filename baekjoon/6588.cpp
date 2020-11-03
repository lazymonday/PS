#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int notp[MAX + 1];
int prime[MAX + 1];

void erato(int maxn) {
	notp[0] = notp[1] = 1;
	for (int i = 2; i * i <= maxn; ++i)
	{
		if (notp[i]) continue;
		for (int j = i * i; j <= maxn; j += i) notp[j] = 1;
	}
}


int main() {
	erato(MAX);
	int n;
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;

		int a, b;
		bool found = false;
		for (int i = 3; i <= n; ++i)
		{
			
			if (!notp[i] && !notp[n-i]) {
				a = i;
				b = n-i;
				found = true;
				break;
			}
		}

		if (found) {
			printf("%d = %d + %d\n", n, a, b);
		} else {
			printf("Goldbach's conjecture is wrong.\n");
		}

	}

	return 0;
}
