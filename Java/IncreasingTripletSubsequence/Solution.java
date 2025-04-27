/*
LeetCode 334. Increasing Triplet Subsequence

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

Example 1
    Input: nums = [1,2,3,4,5]
    Output: true

Example 2
    Input: nums = [5,4,3,2,1]
    Output: false

Example 3
    Input: nums = [2,1,5,0,4,6]
    Output: true
*/

class Solution {

    public static boolean increasingTriplet(int[] nums) {
        
        // declare two ints, defaulting them to max integer value
        int a = Integer.MAX_VALUE;
        int b = Integer.MAX_VALUE;

        for (int n : nums) {

            // a should always be the smallest value we've seen so far
            if (n < a) {
                a = n;
            }
            // b should be the second smallest value we've seen so far (but still greater than a)
            else if (n > a && n < b) {
                b = n;
            }
            // if we can find a current int that is greater than b, when b is also greater than a,
            // then we have found an increasing triplet
            else if (a < b && b < n) {
                return true;
            }
        }
        
        // if we have made it down here, there is no increasing triplet
        return false;
    }

    public static void main(String[] args) {

        int[] input = {5,4,3,2,1,0};
        boolean output = increasingTriplet(input);
        System.out.println("result: " + output);
    }
}