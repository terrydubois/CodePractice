/*
LeetCode 34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1
	Input: nums = [5,7,7,8,8,10], target = 8
	Output: [3,4]

Example 2
	Input: nums = [5,7,7,8,8,10], target = 6
	Output: [-1,-1]
*/


// use binary search to find target
// function for finding leftmost, function for finding rightmost

#include <iostream>
#include <vector>

using namespace std;

// regular binary search
int binarySearch(vector<int>& nums, int target) {
	int l = 0;
	int r = nums.size() - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] > target) r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}

int binarySearchSide(vector<int>& nums, int target, bool leftmost) {

	// if leftmost is true, find the leftmost index of target
	// otherwise, find the rightmost index of target

	int index = -1;
	int l = 0;
	int r = nums.size() - 1;
	while (l <= r) {

		// if mid matches the target, save the index and try to go further left/right
		int mid = l + (r - l) / 2;
		if (nums[mid] == target) {
			index = mid;
			if (leftmost) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		// if mid doesn't match target, follow regular binary search algorithm
		else if (nums[mid] > target) r = mid - 1;
		else l = mid + 1;
	}
	return index;
}

vector<int> searchRange(vector<int>& nums, int target) {

	vector<int> result;
	result.push_back(binarySearchSide(nums, target, true));
	result.push_back(binarySearchSide(nums, target, false));
	return result;
}

void printVec(const vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
		if (i + 1 < vec.size()) cout << ", ";
	}
	cout << endl;
}

int main() {

	vector<int> input = {5,7,7,8,8,10};
	vector<int> output = searchRange(input, 10);
	printVec(output);

	return 0;
}
