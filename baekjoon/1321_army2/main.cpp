#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 500000;
int army[MAX + 1];
vector<int> bucket;
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    int sz = ceil(sqrt(n));
    bucket.resize(sz + 1);

    for (int i = 0; i < n; ++i) {
        cin >> army[i];
        bucket[i / sz] += army[i];
    }

    cin >> m;

    int a, b, c;
    for (int j = 0; j < m; ++j) {
        cin >> a;
        if (a == 1) {
            // update
            cin >> b >> c;
            bucket[(b - 1) / sz] += c;
            army[b - 1] += c;
        } else {
            cin >> b;
            // print
            int sum = 0;
            int cur = 0;
            while (sum + bucket[cur / sz] < b) {
                sum += bucket[cur / sz];
                cur += sz;
            }

            while (sum + army[cur] < b) {
                sum += army[cur++];
            }

            cout << cur + 1 << "\n";
        }
    }

    return 0;
}
