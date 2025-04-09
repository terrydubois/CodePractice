/*
LeetCode 55. Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1
    Input: nums = [2,3,1,1,4]
    Output: true

Example 2
    Input: nums = [3,2,1,0,4]
    Output: false
*/

#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {

    // we will start at the end of the list and work towards the start
    int goalIndex = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--) {

        // at each step, check if we can reach the goal index from the current position
        if (i + nums[i] >= goalIndex) {

            // if we can, we can bump the goalIndex towards the start of the list
            goalIndex = i;
        }
    }

    // if we have bumped the goalIndex all the way to the start of the list, then we can jump
    return goalIndex == 0;
}

int main() {

    vector<int> input = {2,3,1,1,4};
    bool output = canJump(input);
    cout << "result: " << output << endl;

    return 0;
}