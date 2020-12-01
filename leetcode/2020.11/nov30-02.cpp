class Solution {
public:
    typedef long long ll;
    ll n;
    unordered_map<ll, int> t;

    void update(ll l, ll r, int value) {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                t[l] = max(t[l], value);
                l++;
            }
            if (r & 1) {
                r--;
                t[r] = max(t[r], value);
            }
        }
    }

    int query(ll pos) {
        int ret = 0;
        pos += n;
        while (pos) {
            ret = max(ret, t[pos]);
            pos >>= 1;
        }
        return ret;
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& A) {
        vector<vector<int>> res;
        if (A.size() == 0) return res;
        vector<int> vec;
        for (int i = 0; i < A.size(); i++) {
            vec.push_back(A[i][0]);
            vec.push_back(A[i][1]);
        }
        sort(vec.begin(), vec.end());

        n = 1ll * vec[vec.size() - 1] + 1;

        for (int i = 0; i < A.size(); i++) {
            update(A[i][0], A[i][1], A[i][2]);
        }

        int prev = 0;
        for (int i = 0; i < vec.size(); i++) {
            int q = query(vec[i]);
            if (q != prev)
                res.push_back({vec[i], q});
            prev = q;
        }
        return res;
    }
};