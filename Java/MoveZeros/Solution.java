/*
LeetCode 283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example 1:
    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]

Example 2:
    Input: nums = [0]
    Output: [0]
*/

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

class Solution {

    // solving problem using an extra list
    public static void moveZeroesWithList(int[] nums) {
        
        List<Integer> nonZeroes = new ArrayList<Integer>();

        for (int n : nums) {
            if (n != 0) nonZeroes.add(n);
        }

        for (int i = 0; i < nums.length; i++) {
            if (i < nonZeroes.size()) nums[i] = nonZeroes.get(i);
            else nums[i] = 0;
        }
    }

    // better: solving problem using two pointers
    public static void moveZeroes(int[] nums) {

        int nonZeroIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            
            if (nums[i] != 0) {
                // swap num[i] with num[nonZeroIndex]
                int temp = nums[i];
                nums[i] = nums[nonZeroIndex];
                nums[nonZeroIndex] = temp;
                nonZeroIndex++;
            }
        }
    }

    public static void main(String[] args) {

        int[] nums = {0,1,0,3,12};
        moveZeroes(nums);
        System.out.println("result: " + Arrays.toString(nums));
    }
}