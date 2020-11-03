#include <iostream>

using namespace std;

const int MAX = 1e6;
char str[MAX + 1];
int p[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;

    int len = strlen(str);

    int l = -1, r = -1;

    for (int i = 1; i < len; ++i) {
        if (i <= r) {
            p[i] = min(r - i, p[i - l]);
        }
        while (i + p[i] + 1 < len && str[i + p[i] + 1] == str[p[i] + 1]) p[i]++;
        if (p[i] > r) {
            r = p[i];
            l = i;
        }
    }
    
    for (int i = 0; i < len; ++i) {
        cout << p[i] << " ";
    }

    return 0;
}
