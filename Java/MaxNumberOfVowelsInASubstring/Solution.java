/*
LeetCode 1456. Maximum Number of Vowels in a Substring of Given Length

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Example
    Input: s = "abciiidef", k = 3
    Output: 3
*/

import java.util.Set;

class Solution {

    public static boolean isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    public static int maxVowels(String s, int k) {

        int result = 0;
        int currentCount = 0;

        for (int i = 0; i < s.length(); i++) {

            // if the right of our sliding window is a vowel, increment the count of vowels in the window
            char right = s.charAt(i);
            if (isVowel(right)) {
                currentCount++;
            }
            
            if (i >= k) {

                // if the left of our sliding window is a vowel, decrement the count of vowels in the window
                char left = s.charAt(i - k);
                if (isVowel(left)) {
                    currentCount--;
                }
            }

            // make sure the result is always the max amount of vowels
            result = Math.max(result, currentCount);
        }

        return result;
    }

    public static void main(String[] args) {

        String s = "abciiidef";
        int k = 3;
        int result = maxVowels(s, k);
        System.out.println("result: " + result);

    }
}