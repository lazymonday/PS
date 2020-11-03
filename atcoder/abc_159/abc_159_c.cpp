#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int L;
    cin >> L;

    double a = L/(double)3;
    cout << fixed << setprecision(6);
    cout << (a * a * ((double)L-(2*a)));

    return 0;
}
