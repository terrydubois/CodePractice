/*
LeetCode 12. Integer to Roman

Given an integer, convert it to a Roman numeral.

Example 1
    Input: num = 3749
    Output: "MMMDCCXLIX"

Example 2
    Input: num = 58
    Output: "LVIII"
*/

import java.util.HashMap;

class Solution {

    public static String intToRoman(int num) {

        // ordering of how we will try to build the roman numera;
        int[] romanInts = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        // mapping of all roman values, both standard and special cases
        HashMap<Integer, String> romans = new HashMap<Integer, String>();
        romans.put(1000, "M");
        romans.put(900, "CM");
        romans.put(500, "D");
        romans.put(400, "CD");
        romans.put(100, "C");
        romans.put(90, "XC");
        romans.put(50, "L");
        romans.put(40, "XL");
        romans.put(10, "X");
        romans.put(9, "IX");
        romans.put(5, "V");
        romans.put(4, "IV");
        romans.put(1, "I");

        StringBuilder result = new StringBuilder("");
        int romanIntsIndex = 0;
        while (num > 0) {

            // starting from the left of romanInts, check result of divion by current romanInt
            int romanInt = romanInts[romanIntsIndex];
            int attempt = num / romanInt;
            
            // whatever that amount is, that is how many of the current roman string we should use
            for (int i = 0; i < attempt; i++) {
                result.append(romans.get(romanInt));
            }

            // if that amount was at least 1, we need to make our number smaller by doing a mod operation by the current romanInt
            if (attempt >= 1) {
                num = num % romanInt;
            }

            // check the next value in romanInts
            romanIntsIndex++;
        }

        return result.toString();
    }

    public static void main(String[] args) {

        int input = 1994;
        String output = intToRoman(input);
        System.out.println("result: " + output);
    }
}