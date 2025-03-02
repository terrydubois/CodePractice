/*
LeetCode 128. Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1
    Input: nums = [100,4,200,1,3,2]
    Output: 4

Example 2
    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9

Example 3
    Input: nums = [1,0,1,2]
    Output: 3
*/

#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

int longestConsecutive(vector<int>& nums) {

    // a seq starts when we cannot find num - 1 in our set
    // if a seq has started, keep incrementing until we find a number outside of set

    // first, let's convert nums to a set to get rid of duplicates
    unordered_set<int> set(nums.begin(), nums.end());

    int longest = 0;
    for (int num : set) {

        // check if this is the start of a seq (num - 1 is not in set)
        if (set.find(num - 1) == set.end()) {

            // this is the start of a seq, so keep incrementing until we find a number not in set (ending the seq)
            int i = 1;
            while (set.find(num + i) != set.end()) {
                i++;
            }
            
            // i is the length of the current seq, so update longest if we need to
            longest = max(longest, i);
        }
    }

    return longest;
}

int main() {

    vector<int> input = {0,3,7,2,5,8,4,6,0,1};
    int longest = longestConsecutive(input);
    cout << "longest: " << longest << endl;

    return 0;
}