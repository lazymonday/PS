#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

struct Pack {
    float pricePerCard;
    int cardCount;
    int price;

    bool operator<(const Pack &rhs) const {
        return pricePerCard < rhs.pricePerCard;
    }
};

int n;
int packCount;
vector<Pack> packList;
int pack[10000];
char packs[500000]; // 1000 * 50자리[?]
int cache[1000][10000];

const int INF = 1e9;

int buy(int start, int toBuy) {

    if (toBuy == 0) {
        return 0;
    } else if (toBuy < 0) {
        return -INF;
    }

    if (start < 0) {
        return 0;
    }

    int &ret = cache[start][toBuy];
    if (ret != -1) {
        return ret;
    }

    int nextCard = (packList[start].cardCount < toBuy ? start : start - 1);
    ret = max(buy(nextCard, toBuy - packList[start].cardCount) + packList[start].price,
              buy(start - 1, toBuy));

    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    packCount = 0;
    cin >> n;
    cin.getline(packs, 1);
    cin.getline(packs, 500000);
    char *p = strtok(packs, " ");
    while (p != 0) {
        pack[packCount++] = atoi(p);
        p = strtok(0, " ");
    }

    packList.resize(packCount);
    for (int k = 0; k < packCount; ++k) {
        packList[k] = {(float) packCount / (k + 1), k + 1, pack[k]};
    }

    //sort(packList.begin(), packList.end());

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 10000; ++j) {
            cache[i][j] = -1;
        }
    }

    cout << buy(packCount - 1, n) << endl;

    return 0;
}

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int pack[1001] = {0};
//int dp[1001] = {0};
//
//int main() {
//    int n;
//    cin >> n;
//
//    for (int i = 1; i <= n; ++i) {
//        cin >> pack[i];
//    }
//
//    for (int i = 1; i <= n; ++i) {
//        dp[i] = pack[i];
//        for (int j = 1; j <= i / 2; ++j) {
//            dp[i] = max(dp[i], dp[i - j] + dp[j]);
//        }
//    }
//
//    cout << dp[n] << endl;
//    return 0;
//}
