/*
LeetCode 3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

Example 1
    Input: s = "abcabcbb"
    Output: 3

Example 2
    Input: s = "bbbbb"
    Output: 1
*/
import java.util.HashSet;

public class Solution {

    public static int lengthOfLongestSubstring(String s) {
        int longest = 0;
        HashSet<Character> set = new HashSet<Character>();

        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            char c = s.charAt(r);

            while (set.contains(c)) {
                set.remove(s.charAt(l));
                l++;
            }

            set.add(c);
            longest = Math.max(longest, r - l + 1);
        }

        return longest;
    }

    public static void main(String[] args) {
        String input = "aaabc";
        int output = lengthOfLongestSubstring(input);
        System.out.println("result: " + output);
    }
}