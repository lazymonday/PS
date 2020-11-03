#include <iostream>
#include <algorithm>

using namespace std;

int n;
int gem[51];

int solve(int index) {
    if (index++ > n) {
        return 0;
    }

    return max(solve(index) + gem[index], solve(index));
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> gem[i];
    }

    int cost;
    for (int i = 1; i <= n; ++i) {
        cin >> cost;
        gem[i] -= cost;
    }

    int ret = solve(0);
    cout << ret << endl;

    return 0;
}
