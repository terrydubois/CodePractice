/*
LeetCode 45. Jump Game II

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
- 0 <= j <= nums[i] and
- i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

Example 1
    Input: nums = [2,3,1,1,4]
    Output: 2

Example 2
    Input: nums = [2,3,0,1,4]
    Output: 2
*/

#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {

    int farthest = 0;
    int minJumps = 0;
    int curEnd = 0;
    
    // loop from the start to the second to last num
    for (int i = 0; i < nums.size() - 1; i++) {

        // at each position, check if we can reach farther
        farthest = max(farthest, i + nums[i]);
        
        // if we have reached the end of our current jump, increment minJumps and set our new jump goal to be the furthest position so far
        if (i == curEnd) {
            minJumps++;
            curEnd = farthest;
        }
    }

    return minJumps;
}

int main() {

    vector<int> input = {2,3,0,1,4};
    int output = jump(input);
    cout << "result: " << output << endl;

    return 0;
}