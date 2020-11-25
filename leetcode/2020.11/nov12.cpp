class Solution {
public:
    set<vector<int>> cand;

    void perm(vector<bool>& taken, vector<int>& a, vector<int>& selected, int lastPicked) {
        int picked = -1;
        for (int i = 0; i < a.size(); ++i) {
            if (!taken[i]) {
                picked = i;
                break;
            }
        }

        if (picked == -1) {
            if (selected.size() == a.size())
                cand.insert(selected);
            return;
        }

        for (int i = picked; i < a.size(); ++i) {
            if (taken[i]) continue;
            taken[i] = true;
            selected.push_back(a[i]);
            perm(taken, a, selected, i);
            selected.pop_back();
            taken[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<bool> taken(nums.size(), false);
        vector<int> selected;
        perm(taken, nums, selected, -1);
        vector<vector<int>> ans;
        ans.assign(cand.begin(), cand.end());
        return ans;
    }
};