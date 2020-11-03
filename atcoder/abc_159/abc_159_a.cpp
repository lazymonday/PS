#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int comb(int n, int r) {

    if (n < r) {
        return 0;
    } 

    if(n==r || r == 0) {
        return 1;
    }

    int x = 1;
    int y = 1;
    for (int i = 0; i < r; ++i)
    {
        x = x * (n - i);
        y = y * (i + 1);
    }

    return x / y;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    cout << comb(n, 2) + comb(m, 2);


    return 0;
}
