class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int cntA[7] = {0, };
        int cntB[7] = {0, };
        int cntSame[7] = {0, };

        int n = A.size();

        for(int i = 0; i < n; ++i) {
            if(A[i] == B[i]) cntSame[A[i]]++;
            else {
                cntA[A[i]]++;
                cntB[B[i]]++;    
            }
        }

        int ans = 1e9;
        for(int i = 1; i <= 6; ++i) {
            if(cntA[i] + cntB[i] + cntSame[i] == n) {
                ans = min({ans, cntA[i], cntB[i]});
            }
        }

        if(ans == 1e9) return -1;
        return ans;
    }
};