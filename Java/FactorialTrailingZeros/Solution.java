/*
LeetCode 172. Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!

Example 1:
    Input: n = 3
    Output: 0

Example 2:
    Input: n = 5
    Output: 1
*/

class Solution {

    public static int trailingZeros(int n) {

        // trailing zeros indicates the use of factors 2, 5, and 10
        // we shouldn't use 10, because there are numbers < 10 whose factorials have trailing zeros
        // we shouldn't use 2, because 2*2=4, which could result in something other than trailing zeros
        // so, let's count up the amount of factors of 5 in the given number
        
        int zeroCount = 0;
        while (n > 0) {
            n /= 5;
            zeroCount += n;
        }
        return zeroCount;
    }

    public static void main(String[] args) {
        int input = 13;
        int output = trailingZeros(input);
        System.out.println("result: " + output);
    }
}