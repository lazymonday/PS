#include <iostream>

using namespace std;

const int MAX = 12;
const int INF = 1e9;
typedef long long ll;

const int White = 0;
const int Red = 1;
const int Blue = 2;
const int Right = 1;
const int Up = 3;

int dr[] = {0, 0, 0, -1, 1};
int dc[] = {0, 1, -1, 0, 0};

int n, k;
int color[MAX + 1][MAX + 1];
string board[MAX + 1][MAX + 1];

struct chess {
    int r, c, dir;
    bool isBottom;
} ch[11];

int changeDir(int d) {
    if (d == Right || d == Up) d++;
    else d--;
    return d;
}

int move(chess &cur) {
    if (!cur.isBottom) return 0;

    int nr = cur.r + dr[cur.dir];
    int nc = cur.c + dc[cur.dir];

    if (nr < 1 || nr > n || nc < 1 || nc > n || color[nr][nc] == Blue) {
        cur.dir = changeDir(cur.dir);
        nr = cur.r + dr[cur.dir];
        nc = cur.c + dc[cur.dir];
        if (color[nr][nc] == Blue) {
            return 0;
        }
    }

    cur.isBottom = false;
    auto &cur_st = board[cur.r][cur.c];
    auto &next_st = board[nr][nc];
    if (color[nr][nc] == White) {
        next_st.append(cur_st);
    } else if (color[nr][nc] == Red) {
        reverse(cur_st.begin(), cur_st.end());
        next_st.append(cur_st);
        ch[next_st[next_st.size() - 1] - '0'].isBottom = false;
    }
    cur_st.clear();

    int under = next_st[0] - '0';
    ch[under].isBottom = true;
    cur.r = ch[under].r = nr;
    cur.c = ch[under].c = nc;

    return next_st.size();
}

bool proceed() {

    for (int i = 1; i <= k; ++i) {
        if (move(ch[i]) >= 4) {
            return false;
        }
    }

    return true;
}

void printBoard() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << (board[i][j].empty() ? "0" : board[i][j]) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> color[i][j];

    int row, col, d;
    for (int i = 1; i <= k; ++i) {
        cin >> row >> col >> d;
        ch[i] = {row, col, d, true};
        board[row][col] = '0' + i;
    }

    int turns = 0;
    while (turns <= 1000) {
        turns++;
        if (!proceed()) {
            break;
        }
    }

    cout << (turns > 1000 ? -1 : turns);

    return 0;
}
