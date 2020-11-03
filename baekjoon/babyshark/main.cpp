#include <iostream>
#include <queue>

using namespace std;

int n;
int pond[20][20];
bool visited[20][20];
int sharkRow, sharkCol;
int sharkSize = 2;
int numOfEat = 0;

static const int dirs[4][2] = {
        {1,  0}, // right   c, r
        {-1, 0}, // left
        {0,  -1}, // up
        {0,  1}  // down
};

void eatAndMove(int row, int col) {
    pond[row][col] = 0;
    if (++numOfEat == sharkSize) {
        ++sharkSize;
        numOfEat = 0;
    }

    sharkRow = row;
    sharkCol = col;
}

typedef pair<int/*moves*/, pair<int/*row*/, int/*col*/>> PathInfo;

int findToEat(int r, int c) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = false;
        }
    }


    priority_queue<PathInfo, vector<PathInfo>, greater<>> q;
    q.push({0, {r, c}});
    visited[r][c] = true;
    while (!q.empty()) {
        auto item = q.top();
        q.pop();
        int row = item.second.first;
        int col = item.second.second;

        if (pond[row][col] != 0 && pond[row][col] < sharkSize) {
            eatAndMove(row, col);
            return item.first;
        }

        for (int i = 0; i < 4; ++i) {
            int new_row = row + dirs[i][1];
            int new_col = col + dirs[i][0];

            if (new_row >= n || new_row < 0 || new_col >= n || new_col < 0 || visited[new_row][new_col] ||
                sharkSize < pond[new_row][new_col]) {
                continue;
            }

            visited[new_row][new_col] = true;
            q.push({item.first + 1, {new_row, new_col}});
        }
    }

    return 0;
}

int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> pond[i][j];
            if (pond[i][j] == 9) {
                pond[i][j] = 0;
                sharkRow = i;
                sharkCol = j;
            }
        }
    }

    int moves = 0;
    int total = 0;

    while ((moves = findToEat(sharkRow, sharkCol)) != 0) {
        total += moves;
    };

    cout << total << endl;

    return 0;
}
