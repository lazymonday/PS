#include <iostream>
#include <vector>
#include <deque>

typedef std::vector<std::vector<int>> BoardType;

int top = 1;
int currentX, currentY;
int N, M;

bool rotateCube(int cube[7], BoardType& map, int dir) {
    static std::deque<int> horizontal;
    static std::deque<int> vertical;

    if(horizontal.size() == 0) {
        horizontal.push_back(4);
        horizontal.push_back(1);
        horizontal.push_back(3);
    }
    if(vertical.size() == 0) {
        vertical.push_back(2);
        vertical.push_back(1);
        vertical.push_back(5);
        vertical.push_back(6);
    }

    if (dir == 1) {  // east
        if (currentX >= M - 1) {
            return false;
        }

        horizontal.push_front(vertical.back());
        vertical.pop_back();
        vertical.push_back(horizontal.back());
        horizontal.pop_back();
        vertical[1] = horizontal[1];
        ++currentX;
    } else if (dir == 2) {   // west
        if (currentX <= 0) {
            return false;
        }

        horizontal.push_back(vertical.back());
        vertical.pop_back();
        vertical.push_back(horizontal.front());
        horizontal.pop_front();
        vertical[1] = horizontal[1];
        --currentX;
    } else if (dir == 3) {   // north
        if (currentY <= 0) {
            return false;
        }

        vertical.push_back(vertical.front());
        vertical.pop_front();
        horizontal[1] = vertical[1];
        --currentY;
    } else if (dir == 4) {   // south
        if (currentY >= N - 1) {
            return false;
        }

        vertical.push_front(vertical.back());
        vertical.pop_back();
        horizontal[1] = vertical[1];
        ++currentY;
    }

    int bottomIndex = vertical.back() - 1;
    if (map[currentY][currentX] == 0) {
        map.at(currentY).at(currentX) = cube[bottomIndex];
    } else {
        cube[bottomIndex] = map[currentY][currentX];
        map.at(currentY).at(currentX) = 0;
    }

    top = horizontal[1] - 1;
    return true;
}


int main() {
    int k;

    std::cin >> N;
    std::cin >> M;
    std::cin >> currentY;
    std::cin >> currentX;
    std::cin >> k;

    BoardType map;

    for (int i = 0; i < N; ++i) {
        map.push_back(std::vector<int>());
        for (int j = 0; j < M; ++j) {
            int mapValue;
            std::cin >> mapValue;
            map[i].push_back(mapValue);
        }
    }

    std::vector<int> commands;
    for (int i = 0; i < k; ++i) {
        int command;
        std::cin >> command;
        commands.push_back(command);
    }

    int cube[6] = {0,};

    for (int i = 0; i < commands.size(); ++i) {
        if(rotateCube(cube, map, commands[i])) {
            std::cout << cube[top] << std::endl;
        }
    }


    return 0;
}