#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int n;
char s[51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> s;
        int c = 0;
        for (int i = 0; s[i] && c >= 0; ++i) {
            s[i] == '(' ? c++ : c--;
        }
        cout << (c ? "NO\n" : "YES");
    }

    return 0;
}

