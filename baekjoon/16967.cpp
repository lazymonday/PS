#include <bits/stdc++.h>

using namespace std;

const int MAX = 300*2;
const int INF = 1e9;
typedef long long ll;

int row, col, dr, dc;

int arr[MAX + 1][MAX + 1];
int ori[MAX + 1][MAX + 1];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> row >> col >> dr >> dc;

    for (int r = 0; r < row + dr; ++r)
    {
        for (int c = 0; c < col + dc; ++c)
        {
            cin >> arr[r][c];
        }
    }

    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            if (r < dr || c < dc) {
                ori[r][c] = arr[r][c];
            }
        }
    }

    for (int r = dr; r < row + dr; ++r)
    {
        for (int c = dc; c < col + dc; ++c)
        {
            if (r < row || c < col) {
                ori[r][c] = arr[r][c] - ori[r - dr][c - dc];
            }
        }
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cout << ori[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
