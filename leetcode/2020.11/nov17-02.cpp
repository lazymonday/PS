class Solution {
public:
    int mirrorReflection(int p, int q) {
        int cnt_x = 0;
        int dist_y = 0;
        int ans = 0;
        while(true) {
            cnt_x++;
            dist_y += q;
            if(dist_y % p == 0) {
                int y_ = (dist_y / p) % 2;
                int x_ = cnt_x % 2;
                if(x_ == 1 and y_ == 1) ans = 1;
                else ans = (x_ == 1 ? 0 : 2);
                break;
            }
        }

        return ans;
    }
};