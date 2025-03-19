#include <iostream>
#include <vector>

using namespace std;

// regular binary search
int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
}

int searchRotated(vector<int>& nums, int target) {

    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[l] < nums[mid]) {
            // left subarray is sorted
            if (target >= nums[l] && target < nums[mid]) {
                // target is in left subarray, cut off right subarray
                r = mid - 1;
            }
            else {
                // target is in right subarray, cut off left subarray
                l = mid + 1;
            }
        }
        else {
            // left subarray is unsorted, which means right subarray must be sorted
            if (target > nums[mid] && target <= nums[r]) {
                // target is in right subarray, cut off left subarray
                l = mid + 1;
            }
            else {
                // target is in left subarray, cut off right subarray
                r = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

    vector<int> nums = {17, 18, 30, 102, 2, 6};
    for (int i = 0; i < nums.size(); i++) {
        int index = searchRotated(nums, nums[i]);
        cout << "found " << nums[i] << " at index " << index << endl;
    }

    return 0;
}