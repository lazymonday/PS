#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix_2(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 or matrix[0].size() == 0) return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int lo = 0, hi = n*m-1;
        while(lo < hi) {
            auto x = lo + (hi-lo)/2;
            int r = x / m;
            int c = x % m;
            
            if(matrix[r][c] < target) {
                lo = x + 1;
            } else {
                hi = x;
            }
        }
        
        return matrix[lo/m][lo%m] == target;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int lo = 0, hi = matrix.size() - 1;
        while(lo <= hi) {
            auto x = lo + (hi-lo)/2;
            if(matrix[x][0] < target) {
                lo = x + 1;
            } else if(matrix[x][0] > target) {
                hi = x - 1;
            } else return true;
        }
        
        int row = max(0, hi);
        if(matrix[row][0] == target) return true;
        
        lo = 0, hi = matrix[row].size()-1;
        while(lo < hi) {
            auto x = lo + (hi-lo)/2;
            if(matrix[row][x] < target) {
                lo = x + 1;
            } else {
                hi = x;
            }
        }
        
        return matrix[row][lo] == target;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> mat;
    mat.push_back({1,3,5,7});
    mat.push_back({10, 11, 16, 20});
    mat.push_back({23, 30, 34, 60});
    cout << (sol.searchMatrix(mat, -10) ? "True" : "False");
}