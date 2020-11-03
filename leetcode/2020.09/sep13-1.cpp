#include <bits/stdc++.h>

using namespace std;



class Solution {
public:

    bool inRange(const vector<int>& seg, int pt) {
        return seg[0] <= pt && pt <= seg[1];
    }

    bool merge(vector<int>& seg1, vector<int>& seg2) {
        if (inRange(seg1, seg2[0])) {
            seg1[1] = max(seg1[1], seg2[1]);
            return true;
        }

        return false;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        vector<vector<int>> ret;
        if(intervals.size() == 0) {
            ret.push_back(ni);
            return ret;
        }
        
        intervals.push_back(ni);

        sort(intervals.begin(), intervals.end());
        int next = 0;
        for (int i = 0; i < intervals.size() - 1; ) {
            next = i + 1;
            while (merge(intervals[i], intervals[next])) {
                if (++next >= intervals.size()) break;
            }

            ret.push_back(intervals[i]);
            i = next;
        }

        if (next == intervals.size() - 1) {
            ret.push_back(intervals.back());
        }

        return ret;

    }
};

int main() {
    return 0;
}