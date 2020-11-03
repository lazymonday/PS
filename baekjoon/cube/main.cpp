#include <iostream>
#include <vector>

const int Up = 0;
const int Down = 1;
const int Front = 2;
const int Back = 3;
const int Left = 4;
const int Right = 5;

static const int u = 0;
static const int r = 1;
static const int d = 2;
static const int l = 3;

static int sides[4][3] = {
        {0, 1, 2},  // u
        {2, 5, 8},  // r
        {6, 7, 8},  // d
        {0, 3, 6},  // l
};

static const int associates[][4] = {
        {Back,  Right, Front, Left}, // Up   (ccw)
        {Right, Back,  Left,  Front}, // Dn   (ccw)
        {Right, Down,  Left,  Up},    // Front (ccw)
        {Down,  Right, Up,    Left},    // Back  (ccw)
        {Down,  Back,  Up,    Front},    // Left  (ccw)
        {Back,  Down,  Front, Up},    // Right (ccw)
};

static const int associateSides[][4] = {
        {d, l, l, d}, // Up
        {r, u, u, r}, // Dn
        {d, l, l, d},    // Front
        {r, u, u, r},    // Back
        {d, l, l, d},    // Left
        {r, u, u, r},    // Right
};

char cube[6][9];
int cases;  // max 100
int numOfRotate;
using namespace std;

void init() {
    for (int k = 0; k < 6; ++k) {
        for (int i = 0; i < 9; ++i) {
            char fill = ' ';
            switch (k) {
                case Up:
                    fill = 'w';
                    break;
                case Down:
                    fill = 'y';
                    break;
                case Front:
                    fill = 'r';
                    break;
                case Back:
                    fill = 'o';
                    break;
                case Left:
                    fill = 'g';
                    break;
                case Right:
                    fill = 'b';
                    break;
                default:
                    break;
            }
            cube[k][i] = fill;
        }
    }
}

string printPlane(int plane) {

    string ret;
    for (int i = 0; i < 9; ++i) {
        ret += cube[plane][i];
        if ((i + 1) % 3 == 0) {
            ret += "\n";
        }
    }

    return ret;
}

int getDir(char dir) {
    switch (dir) {
        case 'L':
            return Left;
        case 'F':
            return Front;
        case 'R':
            return Right;
        case 'B':
            return Back;
        case 'U':
            return Up;
        case 'D':
            return Down;
        default:
            return -1;
    }

    return -1;
}

void getSide(int plane, int side, char *out, bool isVertical) {
    for (int i = 0; i < 3; ++i) {
        out[isVertical ? i * 5 : i] = cube[plane][sides[side][i]];
    }
}

void setSide(int plane, int side, char *val, bool vertical) {
    for (int i = 0; i < 3; ++i) {
        cube[plane][sides[side][i]] = val[vertical ? i * 5 : i];
    }
}

void rotatePlane(int plane, bool clockwise) {
    char extracted[25];

    static const int x33[] = {6, 7, 8, 11, 12, 13, 16, 17, 18};
    static const int cw33[] = {8, 13, 18, 7, 12, 17, 6, 11, 16};
    static const int ccw33[] = {16, 11, 6, 17, 12, 7, 18, 13, 8};

    // rotate 3x3
    for (int i = 0; i < 9; ++i) {
        extracted[clockwise ? cw33[i] : ccw33[i]] = cube[plane][i];
    }

    for (int i = 0; i < 9; ++i) {
        cube[plane][i] = extracted[x33[i]];
    }

    int cw[4] = {9, 21, 5, 1};
    int ccw[4] = {5, 1, 9, 21};

    // rotate side x 4
    for (int i = 0; i < 4; ++i) {
        getSide(associates[plane][i], associateSides[plane][i], extracted + (clockwise ? cw[i] : ccw[i]),
                i % 2 == 0);
    }

    // apply original cube
    int startIndex[4] = {1, 9, 21, 5};
    for (int i = 0; i < 4; ++i) {
        setSide(associates[plane][i], associateSides[plane][i], extracted + startIndex[i], i % 2 == 1);
    }
}

void rotateCube(vector<string> rotateInfos) {

    for (int i = 0; i < numOfRotate; ++i) {
        const string &info = rotateInfos[i];
        bool isClockwise = (info[1] == '+');
        char dir = info[0];

        rotatePlane(getDir(dir), isClockwise);
    }
}

int main() {

    init();
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> cases;

    string ret;

    while (--cases >= 0) {
        cin >> numOfRotate;
        vector<string> rotateInfo;
        for (int i = 0; i < numOfRotate; ++i) {
            string info;
            cin >> info;
            rotateInfo.push_back(info);
        }

        rotateCube(rotateInfo);
        ret += printPlane(Up);
        init();
    }

    cout << ret << endl;
    return 0;
}
