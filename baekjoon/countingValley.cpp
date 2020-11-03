#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {

    int ans = 0;
    int h = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'U') ++h;
        else if (s[i] == 'D') --h;

        if (h == 0 && s[i] == 'U') ans++;
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
