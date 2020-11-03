#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 3e5 * 2;
int lps[MAX + 1];
char str[MAX + 1];


void manachers(int len, int &ans) {
    int r = -1, c = -1;

    for (int i = 0; i < len; ++i) {
        if (r >= i) {
            lps[i] = min(r - i, lps[2 * c - i]);
        } else {
            lps[i] = 0;
        }

        while (i + lps[i] + 1 < len && i - lps[i] - 1 >= 0 && str[i + lps[i] + 1] == str[i - lps[i] - 1]) ++lps[i];

        if (r < i + lps[i]) {
            r = i + lps[i];
            c = i;
        }
    }
}

int main() {

    int z;
    cin >> z;
    while (z--) {
        string s;
        cin >> s;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            str[i * 2 + 1] = s[i];
        }
        len = len * 2 + 1;
        int ans = 0;
        manachers(len, ans);

        for (int j = 0; j < len; j += 2) {
            int k = (lps[j] % 4 ? lps[j] - 2 : lps[j]);

            while (k > ans) {
                if (lps[j - k / 2] >= k / 2 && lps[j + k / 2] >= k / 2) ans = k;
                k -= 4;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
