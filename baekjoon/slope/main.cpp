#include <iostream>


int n;
int l;
int ground[101][101];

int countPath(bool checkRowOrNot) {

    int way = 0;

    // check row first
    int curWindow, prevWindow;
    int curHeight, prevHeight;

    for (int i = 0; i < n; ++i) {
        curWindow = 1;
        prevWindow = -1;
        bool canPass = true;
        for (int j = 1; j < n; ++j) {
            int dt;
            if(checkRowOrNot) {
                dt = abs(ground[i][j] - ground[i][j - 1]);
                curHeight = ground[i][j-1];
            } else {
                dt = abs(ground[j][i] - ground[j-1][i]);
                curHeight = ground[j-1][i];
            }

            if (dt == 1) {
                if (prevWindow != -1) {
                    bool curIsLess = curHeight < prevHeight;
                    if (curIsLess) {
                        if (curWindow < l) {
                            canPass = false;
                            break;
                        }
                        curWindow -= l;
                    } else if (prevWindow < l) {
                        canPass = false;
                        break;
                    }
                }

                prevWindow = curWindow;
                prevHeight = curHeight;
                curWindow = 1;
            } else if (dt > 1) {
                canPass = false;
                break;
            } else {
                ++curWindow;
            }

            if (j == n - 1) {
                curHeight = checkRowOrNot ? ground[i][n-1] : ground[n-1][i];
                if (prevWindow != -1) {
                    bool curIsLess = curHeight < prevHeight;
                    if (curIsLess) {
                        if (curWindow < l) {
                            canPass = false;
                        }
                        curWindow -= l;
                    } else if (prevWindow < l) {
                        canPass = false;
                    }
                }
            }
        }

        if (canPass) {
            ++way;
            //std::cout << "passable " << (checkRowOrNot ? "rows : " : "cols : ") << i << std::endl;
        }
    }

    return way;
}

int main() {

    std::cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> ground[i][j];
        }
    }

    std::cout << countPath(true) + countPath(false) << std::endl;

    return 0;
}
