// NOTE : 이거는 안돌아가는 소스임...

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1e3;
const int INF = 2e9;
typedef long long ll;

string a[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string top;
    int maxlen = 0;
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
        if (a[i].size() > maxlen) {
            maxlen = a[i].size();
            top = a[i];
        } else if (a[i].size() == maxlen && top < a[i]) {
            top = a[i];
        }
    }

    sort(a, a + k, [](const string & a, const string & b) {
        int l1 = a.size(), l2 = b.size();
        if (l1 == l2) {
            return strcmp(a.c_str(), b.c_str()) > 0;
        }

        int minn = min(l1, l2);
        const char* longer = (l1 > l2 ? a.c_str() : b.c_str());
        int s1 = minn + 1, s2 = 0;
        for (int i = 0; i < minn; ++i)
        {
            if (longer[s1] == longer[s2]) {
                s1++, s2++;
                s1 %= l1;
                s2 %= l2;
            } else {
                if (longer[s1] < longer[s2]) {
                    return l1 < l2;
                } else {
                    return l1 > l2;
                }
            }
        }

        return false;
    });

    bool once = false;
    for (int i = 0; i < k; ++i)
    {
        cout << a[i];
        if (a[i] == top && !once) {
            once = true;
            int t = n - k;
            while (t-- > 0) cout << top;
        }
    }

    return 0;
}
