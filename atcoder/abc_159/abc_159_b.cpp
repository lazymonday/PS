#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int lps[202];
char str[202];

void manachers(int len) {
    int c = -1;
    int r = -1;

    for (int i = 0; i < len; ++i) {
        if (r >= i) {
            lps[i] = min(r - i, lps[c * 2 - i]);    // pos of symmetric
        } else {
            lps[i] = 0;
        }

        while ((i + lps[i] + 1) < len && (i - lps[i] - 1) >= 0 && (str[i + lps[i] + 1] == str[i - lps[i] - 1]))
            ++lps[i];

        if (r < i + lps[i]) {
            r = i + lps[i];
            c = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char s[101];
    cin >> s;

    int len = strlen(s);
    for (int i = 0; i < len; ++i)
    {
        str[i * 2 + 1] = s[i];
    }
    len = len * 2 + 1;

    manachers(len);

    int mid = len / 2;
    int left = mid / 2;
    int right = (mid + len) / 2;
    int half = len / 2;

    //printf("%d, %d, %d, len : %d", left, mid, right, half);

    if (lps[mid] == half && lps[left] == half / 2 && lps[right] == half / 2) {
        cout << "Yes";
    } else {
        cout << "No";
    }


    return 0;
}
