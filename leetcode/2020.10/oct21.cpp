class Solution {
public:
    vector<int> asteroidCollision(vector<int>& p) {
        vector<int> ret;
        for (int i = 0; i < p.size(); ++i) {
            bool removed = false;
            while (!ret.empty() && ret.back() > 0 and p[i] < 0) {
                int l = abs(ret.back());
                int r = abs(p[i]);
                if (l < r) {
                    ret.pop_back();
                } else if (l > r) {
                    removed = true;
                    break;
                } else {
                    ret.pop_back();
                    removed = true;
                    break;
                }
            }
            if (!removed) ret.push_back(p[i]);
        }

        return ret;
    }
};