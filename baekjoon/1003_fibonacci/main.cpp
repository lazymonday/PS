#include <iostream>

using namespace std;

const int MAX = 40;
int D[MAX + 1];

int main() {

    D[1] = 1;
    D[2] = 1;

    for (int i = 3; i <= MAX; ++i) {
        D[i] = D[i - 1] + D[i - 2];
    }

    int n;
    cin >> n;

    int num;
    for (int j = 0; j < n; ++j) {
        cin >> num;
        if (num == 0) {
            cout << 1 << " " << 0 << "\n";
        } else {
            cout << D[num - 1] << " " << D[num] << "\n";
        }
    }

    return 0;
}
