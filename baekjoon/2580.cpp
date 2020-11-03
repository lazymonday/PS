#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int a[10][10];
int usedRow[10][10];
int usedCol[10][10];
int usedSq[10][10];

inline int sqIndex(int row, int col) {
    return (row / 3 * 3) + (col / 3);
}

inline void setUsed(int r, int c, bool used = true) {
    usedRow[r][a[r][c]] = usedCol[c][a[r][c]] = usedSq[sqIndex(r, c)][a[r][c]] = (used ? 1 : 0);
}

bool solve(int index) {

    if (index == 81) {
        return true;
    }

    int row = index / 9;
    int col = index % 9;

    bool ret = false;
    if (a[row][col] == 0) {
        for (int x = 0; x < 10; ++x) {
            if (usedRow[row][x] == 0 && usedCol[col][x] == 0 && usedSq[sqIndex(row, col)][x] == 0) {
                a[row][col] = x;
                setUsed(row, col);
                if (solve(index + 1)) return true;
                setUsed(row, col, false);
                a[row][col] = 0;
                // 이거 순서 잘못 돼서 하...
            }
        }

    } else {
        ret = solve(index + 1);
    }

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> a[i][j];
            setUsed(i, j);
        }
    }

    solve(0);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
