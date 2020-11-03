#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {

    long quotient = n / s.size();
    long rest = n % s.size();
    long cnt = 0, restCnt = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'a') {
            cnt++;
            if (i < rest) {
                restCnt++;
            }
        }
    }

    return quotient * cnt + restCnt;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    cout << result << "\n";

//    fout.close();

    return 0;
}
