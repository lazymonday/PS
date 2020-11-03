#include <iostream>

using namespace std;

int generate(int a, int b, int t) {
    if (t - a < 0) {
        return 0;
    }

    return generate(a, b, t - a) + b;
}

int main() {

    int a, b, t;
    cin >> a >> b >> t;

    cout << generate(a, b, t) << endl;

    return 0;
}
