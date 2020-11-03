#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int apt[25][25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n;
vector<int> numbering;

int dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n || apt[r][c] <= 0) {
        return 0;
    }

    apt[r][c] *= -1;

    int ret = 1;
    for (int i = 0; i < 4; ++i) {
        ret += dfs(r + dy[i], c + dx[i]);
    }

    return ret;
}


int main() {

    cin >> n;
    for (int r = 0; r < n; ++r) {
        string s;
        cin >> s;
        for (int c = 0; c < n; ++c) {
            apt[r][c] = (s[c] == '0' ? 0 : 1);
        }
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            int ret = dfs(r, c);
            if (ret != 0) {
                numbering.push_back(ret);
            }
        }
    }

    sort(numbering.begin(), numbering.end());
    cout << numbering.size() << "\n";
    for (int i = 0; i < numbering.size(); ++i) {
        cout << numbering[i] << endl;
    }

    return 0;
}
