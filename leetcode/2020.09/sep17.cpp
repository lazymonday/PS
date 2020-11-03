#include <bits/stdc++.h>

using namespace std;


const int dr[] = {0, 1, 0, -1};
const int dc[] = { -1, 0, 1, 0};

class Solution {
public:

    const int Left = 0, Up = 1, Right = 2, Down = 3;
    int cc = 0, cr = 0;

    int rotateDir(int currDir, char dir) {
        if (dir == 'R') {
            if (++currDir > 3) currDir = 0;
        } else if (dir == 'L') {
            if (--currDir < 0) currDir = 3;
        }
        return currDir;
    }

    void move(int dir) {
        cc += dc[dir];
        cr += dr[dir];
    }

    bool isRobotBounded(string instructions) {

        int newDir[4];
        pair<int, int> dt[4];
        for (int i = 0; i < 4; ++i) {
            int currDir = i;
            cc = 0, cr = 0;
            for (auto x : instructions) {
                if (x == 'G') move(currDir);
                else currDir = rotateDir(currDir, x);
            }

            newDir[i] = currDir;
            dt[i] = {cc, cr};

            if (cc == 0 && cr == 0) return true;
        }


        pair<int, int> curr = {0, 0};
        int dir = Up;
        for (int i = 0; i < 100; ++i) {
            curr.first += dt[dir].first;
            curr.second += dt[dir].second;
            dir = newDir[dir];

            if (curr.first == 0 && curr.second == 0) {
                return true;
            }
        }

        return false;
    }
};

bool isRobotBounded(string instructions) {

    // hash map giving the new directions in which we will be facing
    unordered_map<char, pair<char, char>> dir{{'N', {'W', 'E'}}, {'S', {'E', 'W'}}, {'E', {'N', 'S'}}, {'W', {'S', 'N'}}};

    // hashmap giving the change in the cordinates after moving in particular direction
    unordered_map<char, pair<int, int>> moves{{'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', { -1, 0}}};

    // initial position of robot
    int i = 0, j = 0;

    // initial facing direction
    char facing = 'N';


    for (auto c : instructions)
    {
        if (c == 'L')
        {
            facing = dir[facing].first;
        }

        else if (c == 'R')
        {
            facing = dir[facing].second;
        }

        else if (c == 'G')
        {
            i += moves[facing].first;
            j += moves[facing].second;
        }

    }

    if (i == 0 and j == 0)
    {
        return true;
    }

    return facing != 'N';


}

int main() {

    cout << isRobotBounded("GL");
    return 0;
}