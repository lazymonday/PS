#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1e5;

int g, p;
int parent[MAX + 1];
int landed;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> g >> p;
    for (int i = 1; i <= g; ++i) parent[i] = i;
    int plane;
    for (int i = 0; i < p; ++i)
    {
        cin >> plane;
        int pos = plane;
        while (parent[pos] != pos && pos > 0) {
            pos = parent[pos];
        }
        if (pos == 0) break;
        parent[plane] = pos;
        parent[pos] = pos - 1;
        landed++;
    }

    cout << landed;
    return 0;
}
