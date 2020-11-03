#include <bits/stdc++.h>

using namespace std;

const int MAX = 1 << 18;
const int INF = 1e9;
typedef long long ll;

pair<int, int> cows[MAX];

int upper[MAX + 5];
int lower[MAX + 5];

void init(int node, int val) {

    node += MAX;
    upper[node] += val;
    for(node = node >> 1; node; node >>= 1) {
        upper[]
    }
}

void update(int* tree, int node, int left, int right, int idx, int value) {

    if (idx < left || right < idx) return;

    if (left == right) {
        tree[node] += value;
        return;
    }

    int mid = (left + right) >> 1;

    update(tree, node * 2, left, mid, idx, value);
    update(tree, node * 2 + 1, mid + 1, right, idx, value);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows, cows + N);


    int cx = 0, ci = 0;
    for (int i = 0; i < N; ++i)
    {
        if (cx != cows[i].first) {
            ci++;
            continue;
        }

        cows[i].first = ci;
    }

    sort(cows, cows + N, [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
        if (lhs.second == rhs.second) {
            return lhs.first < rhs.first;
        }

        return lhs.second < rhs.second;
    });

    init(1, 1, MAX + 5);

    for (int i = 0; i < N; ++i)
    {
        
    }



    return 0;
}
