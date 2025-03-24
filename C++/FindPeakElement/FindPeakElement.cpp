#include <iostream>
#include <vector>

using namespace std;

int findPeakIndex(vector<int>& nums) {

    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {

        // find midpoint index
        int mid = l + (r - l) / 2;

        // if midpoint index is larger than the index to its right, cut off the search space on the right
        if (nums[mid] > nums[mid + 1]) {
            r = mid;
        }
        // otherwise, cut off the search space on the left
        else {
            l = mid + 1;
        }
    }

    return l;
}

int main() {

    vector<int> nums = {1, 2, 3, 1};
    int peakIndex = findPeakIndex(nums);

    cout << "peakIndex: " << peakIndex << endl;

    return 0;
}