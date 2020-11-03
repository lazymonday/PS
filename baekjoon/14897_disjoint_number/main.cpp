#include <iostream>
#include <cmath>

const int MAX = 1e6;
const int NUM_MAX = 1e9;

const int freqsz = 100;
struct freqInfo {
    int count, min, max;
};

using namespace std;
int nums[MAX + 1];
freqInfo freq[NUM_MAX / freqsz];
int sz;

struct query {
    int l, r, i;

    bool operator<(const query &rhs) const {
        int l0 = l / sz;
        int l1 = rhs.l / sz;
        return l0 == l1 ? r < rhs.r : l < rhs.l;
    }
};

int answer[MAX + 1];
query q[MAX + 1];
int n;

void incFreq(int num) {
    if(freq[num / freqsz].min > num) {
        freq[num / freqsz].min = num;
        freq[num / freqsz].count++;
    }
}

void decFreq(int num) {
    freq[num / 32] &= ~(1u << (num % 32u));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> nums[i];
    }

    sz = sqrt(n);

    int m;
    cin >> m;
    for (int j = 1; j <= m; ++j) {
        cin >> q[j].l >> q[j].r;
        q[j].i = j;
    }

    sort(q, q + n);

    int l = 0, r = 0;
    for (int k = 1; k <= m; ++k) {
        int left = q[k].l, right = q[k].r;

    }

    return 0;
}
