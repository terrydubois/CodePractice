/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printVec(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// make a hashmap
// each time we encounter a number, check if its compliment is in the map
// if it is, then return that number and its compliment
// if not, log it in the hashmap
vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int, int> compliments;

    int len = nums.size();
    for (int i = 0; i < len; i++) {
        int num = nums[i];
        int compliment = target - num;
        if (compliments.find(compliment) != compliments.end()) {
            // found pair
            return {i, compliments[compliment]};
        }
        compliments[num] = i;
    }

    return {};
}

int main() {

    vector<int> nums = {2,7,11,15};
    vector<int> result = twoSum(nums, 9);

    cout << "result:" << endl;
    printVec(result);
}