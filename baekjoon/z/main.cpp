#include <iostream>

int n, r, c;
int currentCount;
static int move[4][2] = {
        {0, 0},
        {1, 0},
        {-1, 1},
        {1, 0}
};

bool traverseZ(int size, int row, int col) {

    bool ret;
    if(size == 2) {
        for(int i = 0; i < 4; ++i) {
            row += move[i][1];
            col += move[i][0];

            if(r == row && c == col) {
                std::cout << currentCount << std::endl;
                return false;
            }

            ++currentCount;
        }

        ret = true;
    } else {
        ret = traverseZ(size / 2, row, col);
        if(ret) {
            ret = traverseZ(size / 2, row, col + size / 2);
        }
        if(ret) {
            ret = traverseZ(size / 2, row + size / 2, col);
        }
        if(ret) {
            ret = traverseZ(size / 2, row + size / 2, col + size / 2);
        }
    }

    return ret;
}

int main() {

    std::cin >> n >> r >> c;

    int maxSize = 1;
    for(int i = 0; i < n; ++i) {
        maxSize *= 2;
    }

    traverseZ(maxSize, 0, 0);

    return 0;
}