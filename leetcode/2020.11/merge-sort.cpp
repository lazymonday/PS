#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums, int begin, int mid, int end) {
    vector<int> tmp(nums);
    int l = begin, r = mid + 1, curr = begin;
    while (l <= mid and r <= end) {
        if (tmp[l] < tmp[r]) {
            nums[curr++] = tmp[l++];
        } else {
            nums[curr++] = tmp[r++];
        }
    }

    while (l <= mid) {
        nums[curr++] = tmp[l++];
    }
}


void partition(vector<int>& nums, int begin, int end) {
    if (begin == end) return;

    int mid = begin + (end - begin) / 2;
    partition(nums, begin, mid);
    partition(nums, mid + 1, end);

    merge(nums, begin, mid, end);
}

void mergesort(vector<int>& nums) {
    partition(nums, 0, nums.size() - 1);
}


int main() {

    vector<int> nums = {6, 3, 32, 7, 89, 90, 23, 2, 3, 1, 5, 8, 9};
    mergesort(nums);
    for (auto x : nums) {
        cout << x << " ";
    }
    return 0;
}