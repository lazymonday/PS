#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;

int cnt[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        cnt[k]++;
    }

    for (int i = 0; i < 10001; ++i)
    {
        while(cnt[i]--) {
            cout << i << "\n";
        }
    }
    

    return 0;
}