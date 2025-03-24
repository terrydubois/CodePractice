/*
LeetCode 15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    // sort input array so we can handle two pointers easier
    sort(nums.begin(), nums.end());

    // use set to avoid duplicate triplets
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < nums.size(); i++) {

        // create two pointers: j starts to the right of i, k starts at end
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            // if all three pointers add up to 0 we have a triplet, and can move j and k
            if (sum == 0) {
                vector<int> newTriplet = {nums[i], nums[j], nums[k]};
                uniqueTriplets.insert(newTriplet);
                j++;
                k--;
            }
            // if we want sum to be greater, increment j
            else if (sum < 0) {
                j++;
            }
            // if we want sum to be lesser, decrement k
            else {
                k--;
            }
        }
    }

    // return a vector of all unique triplets
    vector<vector<int>> result;
    for (auto triplet : uniqueTriplets) {
        result.push_back(triplet);
    }
    return result;
}

void printVec(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i + 1 < vec.size()) cout << ", ";
    }
    cout << endl;
}

void printVecVec(vector<vector<int>>& vecVec) {
    for (int i = 0; i < vecVec.size(); i++) {
        printVec(vecVec[i]);
    }
}

int main() {

    vector<int> nums = {0,0,0,0};
    vector<vector<int>> triplets = threeSum(nums);

    cout << "input: ";
    printVec(nums);
    cout << "output: ";
    printVecVec(triplets);
    
    return 0;
}