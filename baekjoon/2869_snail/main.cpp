#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int a, b, v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> v;
    // a not equal b
    int day = ceil((double) (v - a) / (a - b)) + 1;
    cout << day;

    return 0;
}
