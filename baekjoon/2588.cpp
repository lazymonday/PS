#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int bb = b;
    while(bb) {
        int r = bb % 10;
        cout << a * r << "\n";
        bb /= 10;
    }

    cout << a * b;

    return 0;
}
