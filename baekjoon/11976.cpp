#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int first[4];
int second[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sum[2] = {0, 0};
    for (int i = 0; i < 4; ++i) {
        cin >> first[i] >> second[i];
        sum[0] += first[i];
        sum[1] += second[i];
    }

    int newbie = sum[1] - sum[0];

    first[0] += newbie;

    int a = first[0] - second[0];
    first[1] += a;
    int b = first[1] - second[1];
    first[2] += b;
    int c = first[2] - second[2];

    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";

    return 0;
}
