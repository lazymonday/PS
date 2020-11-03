#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
int n;

int order[MAX + 1];
int sa[MAX + 1];
int len;

// build suffix array in O(nlog^2n)
bool cmp(const int &a, const int &b) {
    if (order[a] != order[b]) {
        return order[a] < order[b];
    }

    if (a + len < n && b + len < n) {
        return order[a + len] < order[b + len];
    } else {
        return a > b;
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    n = str.size();

    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        order[i] = str[i];
    }

    len = 1;
    while (true) {

        int tmp[MAX + 1] = {0};
        sort(sa, sa + n, cmp);

        for (int i = 0; i < n - 1; ++i) {
            tmp[i + 1] = tmp[i] + (cmp(sa[i], sa[i + 1]) ? 1 : 0);
        }

        for (int j = 0; j < n; ++j) {
            order[sa[j]] = tmp[j];
        }

        if (tmp[n - 1] == n - 1) {
            break;
        }

        len *= 2;
    }

    for (int k = 0; k < n; ++k) {
        printf("%d\n", sa[k]);
    }

    return 0;
}
