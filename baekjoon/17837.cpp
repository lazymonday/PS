#include <bits/stdc++.h>

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
} ch[10];

int changeDir(int d) {
    if (d == Right || d == Up) d++;
    else d--;
    return d;
}

int move(chess &cur, int idx) {
    int nr = cur.r + dr[cur.dir];
    int nc = cur.c + dc[cur.dir];

    if (nr < 1 || nr > n || nc < 1 || nc > n || color[nr][nc] == Blue) {
        cur.dir = changeDir(cur.dir);
        nr = cur.r + dr[cur.dir];
        nc = cur.c + dc[cur.dir];
        if (nr < 1 || nr > n || nc < 1 || nc > n || color[nr][nc] == Blue) {
            return 0;
        }
    }

    auto pos = board[cur.r][cur.c].find('0' + idx);
    auto cur_st = board[cur.r][cur.c].substr(pos);
    auto &next_st = board[nr][nc];
    if (color[nr][nc] == White) {
        next_st.append(cur_st);
    } else if (color[nr][nc] == Red) {
        next_st.insert(next_st.end(), cur_st.rbegin(), cur_st.rend());
    }

    board[cur.r][cur.c] = board[cur.r][cur.c].substr(0, pos );
    for (int i = 0; i < cur_st.size(); ++i)
    {
        ch[cur_st[i] - '0'].r = nr;
        ch[cur_st[i] - '0'].c = nc;
    }

    return next_st.size();
}

bool proceed() {
    for (int i = 0; i < k; ++i) {
        if (move(ch[i], i) >= 4) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> color[i][j];

    int row, col, d;
    for (int i = 0; i < k; ++i) {
        cin >> row >> col >> d;
        ch[i] = {row, col, d};
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
