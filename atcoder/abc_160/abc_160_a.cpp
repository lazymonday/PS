#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    if(s[2]==s[3] && s[4]==s[5]) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
