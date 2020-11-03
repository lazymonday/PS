class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double g[101][101] = {0.0, };
        g[0][0] = poured;
        
        for(int r = 0; r <= query_row; ++r) {
            for(int c = 0; c <= r; ++c) {
                if(g[r][c] > 1.0) {
                    double pour = (g[r][c] - 1.0) / 2.0;
                    g[r+1][c] += pour;
                    g[r+1][c+1] += pour;
                    g[r][c] = 1.0;
                }
            }
            
        }
        
        return g[query_row][query_glass];
    }
};