#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    double taxA = 0.08;
    double taxB = 0.1;

    pair<int, int> ta = {ceil(a / taxA), floor((a + 1) / taxA)};
    pair<int, int> tb = {ceil(b / taxB), floor((b + 1) / taxB)};

    if (ta > tb) swap(ta, tb);
    if (ta.first <= tb.first && tb.first < ta.second) {
        cout << tb.first;
    } else {
        cout << -1;
    }
    return 0;
}
