import java.util.Set;
import java.util.HashMap;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;

class Solution {

    public static boolean closeStrings(String word1, String word2) {

        // words should be of same length
        if (word1.length() != word2.length()) return false;
        int len = word1.length();

        // get counts for each char in both words
        HashMap<Character, Integer> word1CharCounts = new HashMap<Character, Integer>();
        HashMap<Character, Integer> word2CharCounts = new HashMap<Character, Integer>();
        for (int i = 0; i < len; i++) {

            // increment count for char in word1
            char word1Char = word1.charAt(i);
            int word1CharCount = 0;
            if (word1CharCounts.containsKey(word1Char)) word1CharCount = word1CharCounts.get(word1Char);
            word1CharCount++;
            word1CharCounts.put(word1Char, word1CharCount);

            // increment count for char in word2
            char word2Char = word2.charAt(i);
            int word2CharCount = 0;
            if (word2CharCounts.containsKey(word2Char)) word2CharCount = word2CharCounts.get(word2Char);
            word2CharCount++;
            word2CharCounts.put(word2Char, word2CharCount);
        }

        // check if words have exact same set of characters
        Set<Character> word1Chars = word1CharCounts.keySet();
        Set<Character> word2Chars = word2CharCounts.keySet();
        if (!word1Chars.equals(word2Chars)) return false;

        // check if distribution of chars is the same for both words
        ArrayList<Integer> word1CharCountsList = new ArrayList<Integer>(word1CharCounts.values());
        ArrayList<Integer> word2CharCountsList = new ArrayList<Integer>(word2CharCounts.values());
        Collections.sort(word1CharCountsList);
        Collections.sort(word2CharCountsList);
        return word1CharCountsList.equals(word2CharCountsList);
    }

    public static void main(String[] args) {

        boolean result = closeStrings("cabbba", "abbccc");
        System.out.println("result: " + result);
    }
}