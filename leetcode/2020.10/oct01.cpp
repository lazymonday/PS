#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> arr({10, 20, 30, 40, 50});
    auto x = lower_bound(arr.begin(), arr.end(), 5000);
    if (x == arr.end()) {
        cout << *x << "!\n";
    } else
        cout << *x << "\n";

    return 0;
}