#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

unsigned int h, w, k;
char choco[11][1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w >> k;
    for (int i = 0; i < h; ++i)
    {
        cin >> choco[i];
    }

    int minCut = INF;
    for (int mask = 0; mask < 1u << (h - 1); ++mask)
    {
        int cut = __builtin_popcount(mask);
        vector<int> whites(cut + 1, 0);

        int wsize = 1;
        for (int j = 0; j < w; ++j)
        {
            for (int i = 0; i < h; ++i)
            {
                int wi = __builtin_popcount(mask & ((1u << i) - 1u));
                if (choco[i][j] == '1') whites[wi]++;
            }

            if (*max_element(whites.begin(), whites.end()) > k) {
                if (wsize == 1) {
                    cut = INF;
                    break;
                }

                for (auto& x :  whites) x = 0;
                cut++;
                j--;
                wsize = 1;
            } else {
                wsize++;
            }
        }

        minCut = min(minCut, cut);
    }

    cout << minCut;

    return 0;
}
