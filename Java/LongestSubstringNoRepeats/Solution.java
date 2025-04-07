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