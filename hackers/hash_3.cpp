#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {

    for (int i = 0; i < s.size(); ++i) s[i] -= 'a';

    int ret = 0;
    int s1[26], s2[26];
    for (int len = 1; len < s.size(); ++len)
    {
        for (int i = 0; i + len - 1 < s.size(); ++i) {
            memset(s1, 0, sizeof s1);
            for (int k = 0; k < len; ++k) {
                s1[s[i + k]]++;
            }

            for (int j = i + 1; j + len - 1 < s.size(); ++j) {
                memset(s2, 0, sizeof s2);
                for (int k = 0; k < len; ++k) {
                    s2[s[j + k]]++;
                }

                if (memcmp(s1, s2, sizeof s1) == 0) {
                    //printf("len : %d, left : %d, right : %d\n", len, i, j);
                    ret++;
                }
            }
        }
    }

    return ret;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        cout << result << "\n";
    }

    return 0;
}
