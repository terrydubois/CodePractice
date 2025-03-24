/*
LeetCode 167. Two Sum II - Input Array Is Sorted

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

Example 1
	Input: numbers = [2,7,11,15], target = 9
	Output: [1,2]

Example 2
	Input: numbers = [2,3,4], target = 6
	Output: [1,3]

Example 3
	Input: numbers = [-1,0], target = -1
	Output: [1,2]
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// using classic HashMap method
vector<int> twoSumHashMap(vector<int>& numbers, int target) {

	vector<int> result;
    unordered_map<int, int> compliments;
    for (int i = 0; i < numbers.size(); i++) {
    	int num = numbers[i];
    	int compliment = target - num;
    	if (compliments.find(compliment) != compliments.end()) {
    		int result1 = i + 1;
    		int result2 = compliments[compliment] + 1;
    		if (result1 < result2) {
    			result.push_back(result1);
    			result.push_back(result2);
    			return result;
    		}
    		else if (result1 > result2) {
    			result.push_back(result2);
    			result.push_back(result1);
    			return result;
    		}
    	}
    	else {
    		compliments[num] = i;
    	}
    }

    return result;
}

// using two pointer method
vector<int> twoSumTwoPointer(vector<int>& numbers, int target) {

	// because array is sorted:
	// increasing l will increase total
	// decrease r will decrease total

	vector<int> result;
	int l = 0;
	int r = numbers.size() - 1;
	while (l < r) {
		int total = numbers[l] + numbers[r];
		if (total == target) {
			result.push_back(l + 1);
			result.push_back(r + 1);
			return result;
		}
		else if (total > target) {
			r--;
		}
		else {
			l++;
		}
	}

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

	vector<int> input = {2,7,11,15};
	int target = 9;

	vector<int> output = twoSumTwoPointer(input, target);
	cout << "result: ";
	printVec(output);

	return 0;
}

