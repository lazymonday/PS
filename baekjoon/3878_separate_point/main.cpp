#include <iostream>

using namespace std;
typedef long long ll;
int cases, n, m;
typedef pair<int, int> Seg;
const int MAX = 100;
Seg black[MAX + 1];
Seg white[MAX + 1];

inline ll ccw(const Seg &origin, const Seg &a, const Seg &b) {
    Seg first = {a.first - origin.first, a.second - origin.second};
    Seg second = {b.first - origin.first, b.second - origin.second};

    return 1ll * first.first * second.second - 1ll * first.second * second.first;
}

bool cmp(const Seg &a, const Seg &b) {
    auto ret = ccw(pts[0], a, b);
    if (ret == 0) {
        return a < b;
    }

    return ret > 0;

}


int main() {

    cin >> cases;
    while (cases--) {
        cin >> n >> m;
        int x, y;
        memset(black, 0, sizeof black);
        memset(white, 0, sizeof white);

        for (int i = 0; i < n; ++i) {
            cin >> black[i].first >> black[i].second;
        }




        for (int j = 0; j < m; ++j) {
            cin >> black[j].first >> black[j].second;
        }

    }


    return 0;
}
