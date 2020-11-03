#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    int a[5];
    int sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a+5);

    cout << sum / 5 << "\n" << a[2];

    return 0;
}
