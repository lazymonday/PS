class Solution {
public:

    vector<int> getEachNum(string ver) {
        vector<int> ret;

        if (ver.empty()) return ret;

        int num = 0;
        for (int i = 0; i < ver.size(); ++i) {
            if (ver[i] == '.') {
                ret.push_back(num);
                num = 0;
                continue;
            }

            num *= 10;
            num += (ver[i] - '0');
        }


        ret.push_back(num);
        return ret;
    }

    int compareVersion(string version1, string version2) {

        auto ret1 = getEachNum(version1);
        auto ret2 = getEachNum(version2);

        int upper = max(ret1.size(), ret2.size());
        for (int i = 0; i < upper; ++i) {

            int l = (i < ret1.size() ? ret1[i] : 0);
            int r = (i < ret2.size() ? ret2[i] : 0);

            if (l == r) continue;

            if (l < r) return -1;
            else if (l > r) return 1;
        }

        return 0;
    }
};