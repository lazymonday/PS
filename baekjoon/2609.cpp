#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;

	if (a < b) swap(a, b);

	int a1 = a;
	int b1 = b;
	int r = a1 % b1;

	while (r != 0) {
		a1 = b1;
		b1 = r;
		r = a1 % b1;
	}

	cout << b1 << "\n" << a*b / b1 << "\n";

	return 0;
}
