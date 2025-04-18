/*
LeetCode 70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1
    Input: n = 2
    Output: 2

Example 2
    Input: n = 3
    Output: 3
*/

import java.util.HashMap;

class Solution {

    public static HashMap<Integer, Integer> memo = new HashMap<>();

    public static int dfs(int n) {

        // check base case, if we only have 0 or 1 stairs to climb, we have found a new path
        if (n <= 1) {
            return 1;
        }

        // if we already have calculated this path before, we can just get the result we stored in our memo map
        if (memo.containsKey(n)) {
            return memo.get(n);
        }
        
        // if we are down here, this is a new path, so we recursively call DFS to see if we can reach the bottom of the stairs
        int count = dfs(n - 1) + dfs(n - 2);

        // put that calculation into the memo map so we don't need to compute it again
        memo.put(n, count);
        return count;
    }

    public static int climbStairs(int n) {
        return dfs(n);
    }

    public static void main(String[] args) {
        int input = 5;
        int output = climbStairs(input);
        System.out.println("result: " + output);
    }
}