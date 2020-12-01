class Solution {
public:

    struct Segment {
        int pos;
        int height;
        int index;
        bool isLeft;
    };

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Segment> lines;
        int n = buildings.size();
        for (int i = 0; i < n; ++i) {
            int l = buildings[i][0];
            int r = buildings[i][1];
            int h = buildings[i][2];

            lines.push_back({l, h, i, true});
            lines.push_back({r, h, i, false});
        }

        sort(lines.begin(), lines.end(), [](const Segment & lhs, const Segment & rhs) {
            if (lhs.pos == rhs.pos) {
                if (lhs.isLeft == rhs.isLeft) {
                    if (lhs.isLeft) {
                        return lhs.height > rhs.height;
                    } else {
                        return lhs.height < rhs.height;
                    }
                }

                return lhs.isLeft;
            }

            return lhs.pos < rhs.pos;
        });

        priority_queue<pair<int, int>> pq;  // height, index
        int sz = lines.size();
        int prevTop = -1, prevPos = -1;
        vector<vector<int>> ans;
        for (int i = 0; i < sz; ++i) {
            if (lines[i].isLeft) {
                pq.push({lines[i].height, lines[i].index});
            } else {
                while (!pq.empty()) {
                    if (pq.top().second == lines[i].index or
                            buildings[pq.top().second][1] <= lines[i].pos) {
                        pq.pop();
                        continue;
                    }
                    break;
                }
            }

            if (pq.empty()) {
                if (ans.back()[0] != lines[i].pos)
                    ans.push_back({lines[i].pos, 0});
                prevTop = -1;
            } else if (prevTop != pq.top().first) {
                ans.push_back({lines[i].pos, pq.top().first});
                prevTop = pq.top().first;
            }
        }

        return ans;
    }
};