const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, -1, 1};

class Solution {
public:

    int walkable;
    int visited[22][22];
    int ans = 0;
    int rows, cols;

    void walk(int r, int c, int remain, const vector<vector<int>>& grid) {

        visited[r][c] = 1;
        if(grid[r][c] == 2) {
            if(remain == 0) ans++;
            visited[r][c] = 0;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || visited[nr][nc] || grid[nr][nc] == -1) continue;

            walk(nr, nc, remain - 1, grid);
        }

        visited[r][c] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        walkable = 0;
        rows = grid.size();
        cols = grid[0].size();
        int sr = 0, sc = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {sr = r, sc = c;}
                else if(grid[r][c] != -1) walkable++;
            }
        }

        memset(visited, 0, sizeof visited);
        walk(sr, sc, walkable, grid);
        return ans;
    }
};