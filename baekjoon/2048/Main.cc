#include <iostream>
#include <stack>
#include <stdio.h>

int board[21][21];
int n;
int largestNumer = -1;

void printBoard(int bb[21][21], int size, int dir) {

    std::cout << "dir : " << dir << std::endl;
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size; ++j) {
            std::cout << bb[i][j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

class Point {
public:

    Point(int x_, int y_) : x(x_), y(y_) {}

    int x;
    int y;

    Point &operator+=(const Point &rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Point &operator-=(const Point &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    static Point zero;
};

Point Point::zero(0, 0);

int getValue(int bo[21][21], const Point &pt, const Point &dt = Point::zero) {
    return bo[pt.y + dt.y][pt.x + dt.x];
}

void setValue(int bo[21][21], const Point &pt, int value) {
    bo[pt.y][pt.x] = value;
}

bool move(int dir, int origin[21][21], int moved[21][21]) {

    const static Point directions[4] = {
            Point(1, 0),    // right
            Point(0, -1),   // up
            Point(-1, 0),   // left
            Point(0, 1),    // down
    };

    const static Point startLoc[4] = {
            Point(1, 1),
            Point(1, n),
            Point(n, 1),
            Point(1, 1),
    };

    //std::fill(moved[0], moved[0] + sizeof(moved), 0);

    bool anyBlockMoved = false;
    const Point &start = startLoc[dir];
    const Point &dt = directions[dir];

    bool isHorizontal = (dir == 0 || dir == 2);
    Point current(start.x, start.y);
    std::stack<int> buffer;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int curVal = getValue(origin, current);
            if (curVal != 0) {
                buffer.push(curVal);
                setValue(moved, current, 0);
            } else {
                if(buffer.size() > 0) {
                    anyBlockMoved = true;
                }
            }

            current += dt;
        }

        int prev = -1;
        int curVal;
        while (!buffer.empty()) {
            curVal = buffer.top();
            buffer.pop();
            if (prev != -1) {
                int newValue;
                if (prev == curVal) {
                    //newValue = std::min(1024, curVal * 2);
                    newValue = curVal * 2;
                    if (largestNumer < newValue) {
                        largestNumer = newValue;
                    }
                    curVal = -1;
                    anyBlockMoved = true;
                } else {
                    newValue = prev;
                }

                current -= dt;
                setValue(moved, current, newValue);
            }
            prev = curVal;
        }

        if(prev != -1) {
            current -= dt;
            setValue(moved, current, prev);
        }

        if (isHorizontal) {
            current.x = startLoc[dir].x;
            current.y++;
        } else {
            current.y = startLoc[dir].y;
            current.x++;
        }
    }

//    printBoard(origin, n, -1);
//    printBoard(moved, n, dir);

    return anyBlockMoved;
}

void findMaximumNumber(int maxMoves, int prevDir, int origin[21][21]) {

    if (maxMoves == 0) {
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int moved[21][21];
        for(int x = 0; x < 21; ++x) {
            for(int xx = 0; xx < 21; ++xx) {
                moved[x][xx] = 0;
            }
        }

        if(((prevDir + 2) % 4) == i) {
            continue;
        }

        if (!move(i, origin, moved)) {
            continue;
        }

        findMaximumNumber(maxMoves - 1, i, moved);
    }
}


int main() {

    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> board[i][j];
            if (largestNumer < board[i][j]) {
                largestNumer = board[i][j];
            }
        }
    }

    findMaximumNumber(5, -99, board);
    std::cout << largestNumer << std::endl;
    return 0;
}