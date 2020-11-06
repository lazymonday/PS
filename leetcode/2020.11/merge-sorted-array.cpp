/* 
    Problem - https://leetcode.com/problems/merge-sorted-array
    Follow up - Can you solve it with no extra space?
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;
        if(pos < 0) return;
        
        int p1 = m-1, p2 = n-1;
        while(p1 >= 0 and p2 >= 0) {
            if(nums1[p1] >= nums2[p2]) {
                nums1[pos--] = nums1[p1--];
            } else {
                nums1[pos--] = nums2[p2--];
            }
        }
        
        for(int i = p2; i >= 0; --i) nums1[pos--] = nums2[i];
    }
};