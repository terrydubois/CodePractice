/*
LeetCode 1071. Greatest Common Divisor of Strings

For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1
    Input: str1 = "ABCABC", str2 = "ABC"
    Output: "ABC"

Example 2
    Input: str1 = "ABABAB", str2 = "ABAB"
    Output: "AB"
*/

class Solution {

    public static boolean canSubstringMakeString(String substr, String str) {
        int times = str.length() / substr.length();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < times; i++) {
            sb.append(substr);
        }
        return str.equals(sb.toString());
    }

    public static String gcdOfStrings(String str1, String str2) {

        String shorterStr;
        String longerStr;
        if (str1.length() < str2.length()) {
            shorterStr = str1;
            longerStr = str2;
        }
        else {
            shorterStr = str2;
            longerStr = str1;
        }

        String gcd = "";
        StringBuilder gcdAttempt = new StringBuilder();

        for (int i = 0; i < shorterStr.length(); i++) {
            gcdAttempt.append(shorterStr.charAt(i));
            if (canSubstringMakeString(gcdAttempt.toString(), longerStr)
            && canSubstringMakeString(gcdAttempt.toString(), shorterStr)) {
                gcd = gcdAttempt.toString();
            }
        }

        return gcd;
    }

    public static void main(String[] args) {

        String result = gcdOfStrings(
            "ABCABC",
            "ABC"
            );
        System.out.println("result: " + result);
    }
}