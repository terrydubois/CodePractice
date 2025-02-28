/*
LeetCode 33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

Example
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4
*/

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {

    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;
        // check if left subarray is sorted
        else if (nums[l] <= nums[mid]) {
            // left subarray is sorted, so check if target is in left subarray
            if (target >= nums[l] && target < nums[mid]) {
                // target is in left subarray, so cut off the right subarray
                r = mid - 1;
            }
            else {
                // target is in right subarray, so cut off the left subarray
                l = mid + 1;
            }
        }
        else {
            // left subarray is unsorted, so check if target is in right subarray
            if (target > nums[mid] && target <= nums[r]) {
                // target is in right subarray, so cut off the left subarray
                l = mid + 1;
            }
            else {
                // target is in left subarray, so cut off the right subarray
                r = mid - 1;
            }
        }
    }

    return -1;
}

void searchAll(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        int target = nums[i];
        cout << "searching for " << target << ", " << search(nums, target) << endl;
    }
}


int main() {

    vector<int> nums = {3,1};
    searchAll(nums);

    return 0;
}