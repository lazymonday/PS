#include <iostream>
#include <climits>

typedef int LadderType[31][11];

bool descentLadder(LadderType ladder, int n, int h, int startCol) {
    int x = startCol;
    for (int y = 1; y <= h; ++y) {
        int cur = ladder[y][x];
        int prev = x - 1 >= 1 ? ladder[y][x - 1] : -1;

        if (prev == 1) {
            --x;
        } else if (cur == 1) {
            ++x;
        }
    }

    return x == startCol;
}

bool checkAllLadder(LadderType ladder, int n, int h) {
    for (int k = 1; k <= n; ++k) {
        if (!descentLadder(ladder, n, h, k)) {
            return false;
        }
    }

    return true;
}

int drawLineOnLadder(int maxLines, int drawnLines, int tried, LadderType ladder, int n, int h) {
    if (maxLines == drawnLines) {
        // copy ladder
        LadderType copied = {0};
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= n; ++j) {
                copied[i][j] = ladder[i][j];
            }
        }

        if (checkAllLadder(copied, n, h)) {
            return drawnLines;
        }

        return INT_MAX;
    }

    if (tried > n * h) {
        return INT_MAX;
    }

    bool isDrawable = false;
    int y, x;
    for (int i = tried; i <= n * h; ++i) {
        y = (i / n) + 1;
        x = (i % n) + 1;

        if (ladder[y][x] == 0 && ladder[y][x - 1] == 0 && ladder[y][x + 1] == 0) {
            isDrawable = true;
            break;
        }
    }

    if (!isDrawable) {
        return INT_MAX;
    }

    int minDrawLadderCount = INT_MAX;

    ladder[y][x] = 1;
    minDrawLadderCount = std::min(minDrawLadderCount,
                                  drawLineOnLadder(maxLines, drawnLines + 1, tried + 1, ladder, n, h));

    ladder[y][x] = 0;
    minDrawLadderCount = std::min(minDrawLadderCount,
                                  drawLineOnLadder(maxLines, drawnLines, tried + 1, ladder, n, h));

    return minDrawLadderCount;

}

int main() {

    int n, h, m;
    std::cin >> n >> m >> h;

    int x, y;
    LadderType ladder_ = {0};
    for (int i = 0; i < m; ++i) {
        std::cin >> y >> x;
        ladder_[y][x] = 1;
    }

    for (int i = 0; i <= 3; ++i) {
        if (drawLineOnLadder(i, 0, 0, ladder_, n, h) != INT_MAX) {
            std::cout << i << std::endl;
            return 0;
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}