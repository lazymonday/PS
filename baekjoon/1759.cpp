#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int L, C;
char a[20];
const char vowel[6] = "aeiou";

int countVowel(string s) {

    int ret = 0;
    for (auto x : s) {
        for (int i = 0; i < 5; ++i) {
            if (x == vowel[i]) {
                ret++;
                break;
            }
        }
    }

    return ret;
}

void solve(int pos, string s) {
    if (pos >= C) {
        if (s.size() == L) {
            int vowels = countVowel(s);
            if (vowels >= 1 && s.size() - vowels >= 2) {
                cout << s << "\n";
            }
        }

        return;
    }

    solve(pos + 1, s + a[pos]);
    solve(pos + 1, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> L >> C;
    for (int i = 0; i < C; ++i)
    {
        cin >> a[i];
    }

    sort(a, a + C);

    string cand;
    solve(0, cand);

    return 0;
}
