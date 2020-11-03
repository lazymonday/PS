#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

static const int maxSize = 10;
static const int initSubstance = 5;
int n, m, k;

deque<int> trees[maxSize][maxSize];

static const int directions[8][2] = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0,  -1},
        {0,  1},
        {1,  -1},
        {1,  0},
        {1,  1}
};

int ground[maxSize][maxSize];
int nutrition[maxSize][maxSize];
int treeCount = 0;

void passYear() {

    // spring
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //sort(trees[i][j].begin(), trees[i][j].end());
            for (int k = 0; k < trees[i][j].size(); ++k) {
                if (ground[i][j] >= trees[i][j][k]) {
                    ground[i][j] -= trees[i][j][k];
                    ++trees[i][j][k];
                } else {
                    trees[i][j][k] *= -1;
                }
            }
        }
    }
    // summer
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = trees[i][j].size() - 1; k >= 0; --k) {
                if (trees[i][j][k] < 0) {
                    ground[i][j] -= (trees[i][j][k]) / 2;
                    trees[i][j].pop_back();
                    --treeCount;
                } else {
                    break;
                }
            }
        }
    }

    // autumn
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < trees[i][j].size(); ++k) {
                if (trees[i][j][k] % 5 != 0) {
                    continue;
                }

                for (int l = 0; l < 8; ++l) {
                    int row = i + directions[l][0];
                    int col = j + directions[l][1];

                    if (row < 0 || row >= n || col < 0 || col >= n) {
                        continue;
                    }

                    trees[row][col].push_front(1);
                    ++treeCount;
                }
            }
        }
    }

    // winter
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ground[i][j] += nutrition[i][j];
        }
    }
}


int main() {

    cin.tie(0);
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> nutrition[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        int r, c, age;
        cin >> r >> c >> age;
        trees[r-1][c-1].push_front(age);
        ++treeCount;
    }

    // init
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ground[i][j] = initSubstance;
        }
    }

    for (int i = 0; i < k; ++i) {
        passYear();
    }

    cout << treeCount << endl;

    return 0;
}
