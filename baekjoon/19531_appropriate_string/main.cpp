#include <iostream>
#include <string>

using namespace std;

const int MAX = 1e5;
typedef long long ll;

string a[MAX + 1];
bool seen[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int len = a[i].size();
        memset(seen, 0, sizeof seen);
        for (int j = 1; j < len; ++j) {
            int tlen = len - j;
            for (int k = 0; k < n; ++k) {
                if (seen[k] || a[k].size() < tlen) continue;
                if (strncmp(a[i].c_str() + j, a[k].c_str(), tlen) == 0) {
                    seen[k] = true;
                    ans += tlen;
                }
            }
        }
    }

    cout << ans;
    return 0;
}
