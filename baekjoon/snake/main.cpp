#include <iostream>
#include <vector>

class Point {
public:
    Point() : x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    int x, y;
};

class Command {
public:
    Command(int sec, char ch) :
            seconds(sec), command(ch) {}

    int seconds;    // [1, 10000]
    char command;   // D, L
};

int boardSize;
int board[102][102];
std::vector<Command*> commands;
const int FlagApple = 5;

class Snake {
public:
    Point head;
    Point tail;
    int dir;
    int elapsed;
    int lastRunIndex;

    void move(int dir, const Point &pt, Point& ret) {
        static const Point direction[4] = {
                Point(1, 0),
                Point(0, 1),
                Point(-1, 0),
                Point(0, -1),};


        ret.x = pt.x + direction[dir].x;
        ret.y = pt.y + direction[dir].y;
    }

    void nextPos(Point& pt) {
        move(dir, head, pt);
    }

    void oneSecond() {

        //printBoard();
        ++elapsed;

        Point next;
        move(dir, head, next);
        if (board[next.y][next.x] != FlagApple) {
            Point nextTail;
            move(board[tail.y][tail.x] - 1, tail, nextTail);
            board[tail.y][tail.x] = 0;
            tail = nextTail;
        }

        //board[head.y][head.x] = dir + 1;
        head = next;

        if (commands.size() > lastRunIndex && commands[lastRunIndex]->seconds == elapsed) {
            if (commands[lastRunIndex]->command == 'D') {
                dir = (dir + 1) % 4;
            } else {
                dir = (dir - 1 < 0 ? 3 : dir - 1);
            }
            ++lastRunIndex;
        }

        board[head.y][head.x] = dir + 1;
    }

    Snake() :
            head(1, 1),
            tail(1, 1),
            dir(0),
            elapsed(0),
            lastRunIndex(0) {
        board[1][1] = dir + 1;
    }

    void end() {
        elapsed++;
    }
};

bool outOfBoard(const Point &pt) {
    return pt.x <= 0 || pt.x > boardSize ||
           pt.y <= 0 || pt.y > boardSize;

}

bool checkEnd(const Point &nextHead) {
    if ((board[nextHead.y][nextHead.x] >= 1 && board[nextHead.y][nextHead.x] <= 4) ||
        outOfBoard(nextHead)) {
        return true;
    }

    return false;
}

void simulateSnake() {
    Snake snake;
    Point next;
    snake.nextPos(next);
    while (!checkEnd(next)) {
        snake.oneSecond();
        snake.nextPos(next);
    }

    snake.end();

    std::cout << snake.elapsed << std::endl;
}

int main() {

    int numOfApples;
    std::cin >> boardSize;
    std::cin >> numOfApples;

    for(int i = 0 ; i < 102; ++i) {
        for(int j = 0; j < 102; ++j) {
            board[i][j] = 0;
        }
    }

    int y, x;
    while (--numOfApples >= 0) {
        std::cin >> y;
        std::cin >> x;

        board[y][x] = FlagApple;
    }

    int numOfCommands;
    int seconds;
    char cmd;

    std::cin >> numOfCommands;

    while (--numOfCommands >= 0) {
        std::cin >> seconds;
        std::cin >> cmd;
        commands.push_back(new Command(seconds, cmd));
    }

    simulateSnake();
    return 0;
}