#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int a[MAX + 1];
int t[MAX + 1];

void merge(int lo, int mid, int hi) {
    memcpy(t + lo, a + lo, sizeof(int) * (hi - lo + 1));
    int left = lo;
    int right = mid + 1;
    int idx = left;
    while (left <= mid && right <= hi) {
        if (t[left] < t[right]) {
            a[idx++] = t[left++];
        } else {
            a[idx++] = t[right++];
        }
    }

    while (left <= mid) {
        a[idx++] = t[left++];
    }
}


void mergesort(int lo, int hi) {
    if (lo == hi) {
        return;
    }

    int mid = lo + (hi - lo) / 2;
    mergesort(lo, mid);
    mergesort(mid + 1, hi);
    merge(lo, mid, hi);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    mergesort(0, n - 1);

    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << "\n";
    }


    return 0;
}
