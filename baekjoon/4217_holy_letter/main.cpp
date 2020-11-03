#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int h, w;
int image[255][255];
int group[255][255];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

char getAnswer(int adjGroup) {
    static const char *ans = "_WAKJSD";
    return ans[adjGroup];
}

void numbering(int sr, int sc, int groupNo) {
    stack<pair<int, int>> st;
    st.push({sr, sc});
    while (!st.empty()) {
        auto &item = st.top();
        int r = item.first;
        int c = item.second;
        st.pop();

        group[r][c] = groupNo;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dy[i];
            int nc = c + dx[i];

            if (nr < 0 || nr > h + 1 || nc < 0 || nc > w * 4 + 1 || group[nr][nc] || image[nr][nc] != image[r][c]) {
                continue;
            }

            st.push({nr, nc});
        }
    }
}

void dfs(int r, int c, int gn) {
    group[r][c] = gn;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dy[i], nc = c + dx[i];
        if (nr < 0 || nr > h + 1 || nc < 0 || nc > w * 4 + 1 || group[nr][nc] || image[nr][nc] != image[r][c]) {
            continue;
        }

        dfs(nr, nc, gn);
    }
}

int main() {

    int noCase = 1;
    while (true) {
        memset(image, 0, sizeof image);
        memset(group, 0, sizeof group);
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        }

        // decode
        for (int r = 0; r < h; ++r) {
            string line;
            cin >> line;
            for (int c = 0; c < w; ++c) {
                char ch = line[c];
                unsigned int pixels = (isdigit(ch) ? ch - '0' : ch - 'a' + 10);
                if (pixels == 0) {
                    continue;
                }

                for (int i = 0; i < 4; ++i) {
                    image[r + 1][c * 4 + i + 1] = (pixels & (1U << (3 - i))) != 0 ? 1 : 0;
                }
            }
        }

        // numbering
        int groupNo = 0;
        for (int r = 1; r <= h; ++r) {
            for (int c = 1; c <= w * 4; ++c) {
                if (!group[r][c]) {
                    numbering(r, c, ++groupNo);
                }
            }
        }

        // find black and count groups
        vector<set<int>> blacks(groupNo + 1);
        for (int r = 1; r <= h; ++r) {
            for (int c = 1; c <= w * 4; ++c) {
                if (image[r][c] == 1) {
                    for (int i = 0; i < 4; ++i) {
                        int nr = r + dy[i];
                        int nc = c + dx[i];

                        if (nr < 0 || nr > h + 1 || nc < 0 || nc > w * 4 + 1 || image[nr][nc] != 0) {
                            continue;
                        }

                        blacks[group[r][c]].insert(group[nr][nc]);
                    }
                }
            }
        }

        vector<char> answer;
        for (int i = 0; i < blacks.size(); ++i) {
            if (!blacks[i].empty()) {
                answer.push_back(getAnswer(blacks[i].size()));
            }
        }

        sort(answer.begin(), answer.end());
        cout << "Case " << noCase++ << ": ";
        for (int i = 0; i < answer.size(); ++i) {
            cout << answer[i];
        }

        cout << "\n";
    }

    return 0;
}