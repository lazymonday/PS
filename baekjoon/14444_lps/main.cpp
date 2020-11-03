#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1e5 * 2;
char str[MAX + 10];
int lps[MAX + 10];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;
    int len = strlen(str);
    for (int j = len - 1; j >= 0; --j) {
        str[j * 2 + 1] = str[j];
        str[j * 2] = 0; // 0이 아닌 다른걸 넣으면 str[len*2]에도 넣어줘야 함.
    }

    len = len * 2 + 1;
    int ans = 0;
    int r = -1, c = -1;

    for (int i = 0; i < len; ++i) {
        if (i <= r) {
            lps[i] = min(r - i, lps[2 * c - i]);
        }

        while (i + lps[i] + 1 < len && i - lps[i] - 1 >= 0 && str[i + lps[i] + 1] == str[i - lps[i] - 1]) ++lps[i];

        ans = max(ans, lps[i]);

        if (r < i + lps[i]) {
            r = i + lps[i];
            c = i;
        }
    }

    cout << ans;


    return 0;
}
