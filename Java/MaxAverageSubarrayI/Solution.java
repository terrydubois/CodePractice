/*
LeetCode 643. Maximum Average Subarray I

You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

Example 1
    Input: nums = [1,12,-5,-6,50,3], k = 4
    Output: 12.75000

Example 2
    Input: nums = [5], k = 1
    Output: 5.00000
*/

class Solution {

    public static double findMaxAverage(int[] nums, int k) {
        
        // keep track of current sum and max sum
        int sum = 0;
        int maxSum = Integer.MIN_VALUE;

        // use two pointers to create a sliding window
        int len = nums.length;
        int l = 0;
        int r = 0;

        while (r < len) {

            // add right pointer's number to current sum
            sum += nums[r];

            // if our window is the size we want...
            if (r - l + 1 == k) {
                
                // check if max sum has increased
                maxSum = Math.max(maxSum, sum);

                // slide left pointer forward
                sum -= nums[l];
                l++;
            }

            // slide right pointer forward
            r++;
        }

        // the max average comes from the max sum
        return (double) maxSum / k;
    }

    public static void main(String[] args) {

        int[] nums = {1,12,-5,-6,50,3};
        int k = 4;
        double result = findMaxAverage(nums, k);
        System.out.println("result: " + result);
    }
}