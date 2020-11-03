#include <iostream>
#include <algorithm>

using namespace std;

int a[] = {1, 4, 7, 9, 10, 10, 12, 14, 16};

int lb(int lo, int hi, int k) {

    while (lo < hi) {
        printf("[%d, %d] ", lo, hi);
        int mid = (lo + hi) >> 1;
        if (a[mid] < k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    printf("\n");

    return lo;
}

int ub(int lo, int hi, int k) {

    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (a[mid] > k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    return hi;
}


int main() {
    int k = 16;
    cout << lower_bound(a, a + 9, k) - a << "\n";
    cout << lb(0, 9, k) << "\n";
    cout << upper_bound(a, a + 9, k) - a << "\n";
    cout << ub(0, 9, k) << "\n";
    return 0;
}
