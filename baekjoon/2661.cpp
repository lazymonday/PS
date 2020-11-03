#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 80;
const int INF = 2e9;
typedef long long ll;

int n;
char s[MAX + 1];

bool check(int len) {
	for (int i = 1; i * 2 <= len; ++i)
	{
		if (strncmp(s + len - i, s + len - (i * 2), i) == 0)
			return false;
	}

	return true;
}

bool solve(int pos) {

	if (pos == n) {
		if (check(pos)) {
			s[pos] = 0;
			printf("%s", s);
			return true;
		}
	}

	for (int i = 1; i <= 3; ++i)
	{
		if (i == s[pos - 1] - '0') continue;
		s[pos] = i + '0';
		if (check(pos) && solve(pos + 1)) {
			return true;
		}
	}

	return false;
}

int main() {

	scanf("%d", &n);

	solve(0);

	return 0;
}
