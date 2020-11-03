#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e3;
const int INF = 2e9;
typedef long long ll;

int a[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n; ++i)
    {
        int tmp = a[i];
        int j = i - 1;
        while (a[j] > tmp && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }

    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << "\n";
    }


    return 0;
}
