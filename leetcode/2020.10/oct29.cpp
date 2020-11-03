class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int begin = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (seats[i]) {
                if (begin == -1) {
                    begin = i;
                } else {
                    if (begin == 0 and seats[0] == 0) {
                        ans = max(i, ans);
                    } else {
                        ans = max((i - begin) / 2, ans);
                    }

                    begin = i;
                }
            }
        }

        if (begin != -1) {
            ans = max(ans, n - begin - 1);
        }

        return ans;
    }
};