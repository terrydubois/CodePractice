/*
LeetCode 2300. Successful Pairs of Spells and Potions

You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

Example 1
    Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
    Output: [4,0,3]

Example 2
    Input: spells = [3,1,2], potions = [8,5,8], success = 16
    Output: [2,0,2]
*/

import java.util.Arrays;

class Solution {
    
    public static int[] successfulPairs(int[] spells, int[] potions, long success) {

        // our result will have a count of pairs for each spell, so it should be as long as the spells array
        int[] result = new int[spells.length];

        // sort potions so that once we find a potion that works for the current spell, we don't need to check any further
        Arrays.sort(potions);

        for (int i = 0; i < spells.length; i++) {

            // get current spell
            int spell = spells[i];

            // use binary search to find lowest potion where spell*potion >= success
            int lowestPotionIndex = potions.length;
            int l = 0;
            int r = potions.length - 1;
            while (l <= r) {
                int mid = (l + r) / 2;

                // cast product to a long for large numbers
                long product = (long) spell * potions[mid];

                // if product achieved success, store the index and try to go lower
                if (product >= success) {
                    r = mid - 1;
                    lowestPotionIndex = mid;
                }
                // if product did not achieve success, try to go higher
                else {
                    l = mid + 1;
                }
            }

            // the amount of potions that succeed can be found by subtracting lowestPotionIndex from the total amount of potions
            result[i] = potions.length - lowestPotionIndex;
        }

        return result;
    }

    public static void main(String[] args) {

        int[] spells = {5,1,3};
        int[] potions = {1,2,3,4,5};
        long success = 7;
        int[] result = successfulPairs(spells, potions, success);

        System.out.println("result: " + Arrays.toString(result));
    }
}