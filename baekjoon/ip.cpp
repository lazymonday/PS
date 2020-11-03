#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

bool isPalindrome(string s, int left, int right) {

    while(left < right && s[left] == s[right]) {
        left++;
        right--;
    }

    return left == right;
}

bool isPalindrome(string s) {
    string t(s.rbegin(), s.rend());
    return s == t;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s("aba");

    cout << isPalindrome(s, 0, s.size()-1);

    return 0;
}
