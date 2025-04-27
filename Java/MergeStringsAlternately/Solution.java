/*
LeetCode 1768. Merge Strings Alternately

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.

Example 1
    Input: word1 = "abc", word2 = "pqr"
    Output: "apbqcr"

Example 2
    Input: word1 = "ab", word2 = "pqrs"
    Output: "apbqrs"
*/

class Solution {

    public static String mergeAlternately(String word1, String word2) {
        
        // use a StringBuilder so we can append quickly
        StringBuilder merged = new StringBuilder();

        // track an index for each string
        int index1 = 0;
        int index2 = 0;

        // loop until both indexes have completed their strings
        while (index1 < word1.length() || index2 < word2.length()) {

            // if index1 <= index2 or index2 is complete, and index1 is not complete, we will add word1 at index1
            if ((index1 <= index2 || index2 >= word2.length()) && index1 < word1.length()) {
                merged.append(word1.charAt(index1));
                index1++;
            }
            // otherwise, add word2 at index2
            else {
                merged.append(word2.charAt(index2));
                index2++;
            }
        }
        return merged.toString();
    }

    public static void main(String[] args) {
        String merged = mergeAlternately("abcd", "pq");
        System.out.println("result: " + merged);
    }
}