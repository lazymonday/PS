#include <iostream>
#include <stack>

int board[21][21];
int n;

void initBoard(int bb[21][21], int size, int value) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            bb[i][j] = value;
        }
    }
}

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
};

int getValue(const int bo[21][21], const Point &pt, const Point &dt = Point(0, 0)) {
    return bo[pt.y + dt.y][pt.x + dt.x];
}

void setValue(int bo[21][21], const Point &pt, int value) {
    bo[pt.y][pt.x] = value;
}

bool move(int dir, const int origin[21][21], int moved[21][21], int *largest) {

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

    bool anyBlockMoved = false;
    const Point &start = startLoc[dir];
    const Point &dt = directions[dir];

    bool isHorizontal = (dir == 0 || dir == 2);
    Point current(start.x, start.y);

    for (int i = 0; i < n; ++i) {
        std::stack<int> buffer;
        for (int j = 0; j < n; ++j) {
            int curVal = getValue(origin, current);
            if (curVal != 0) {
                buffer.push(curVal);
            } else {
                if (buffer.size() > 0) {
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
                    newValue = curVal * 2;
                    if (*largest < newValue) {
                        *largest = newValue;
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

        if (prev != -1) {
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

void findMaximumNumber(int maxMoves, int prevDir, int origin[21][21], int *largest, int commands[5]) {

    if (maxMoves == 0) {
        return;
    }

    for (int i = 0; i < 4; ++i) {

        // 이전 방향으로 돌아갈 수 있음..
//        if (((prevDir + 2) % 4) == i) {
//            continue;
//        }

        int moved[21][21];
        initBoard(moved, 20, 0);
        if (!move(i, origin, moved, largest)) {
            continue;
        }

        commands[maxMoves - 1] = i;
        findMaximumNumber(maxMoves - 1, i, moved, largest, commands);
    }
}


int main() {

    int largestNumber = -1;
    std::cin >> n;

    initBoard(board, 20, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> board[i][j];
            if (largestNumber < board[i][j]) {
                largestNumber = board[i][j];
            }
        }
    }

    int commands[5] = {};
    findMaximumNumber(5, -99, board, &largestNumber, commands);
    std::cout << largestNumber << std::endl;
    return 0;
}