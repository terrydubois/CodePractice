/*
LeetCode 735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1
    Input: asteroids = [5,10,-5]
    Output: [5,10]

Example 2
    Input: asteroids = [8,-8]
    Output: []

Example 3
    Input: asteroids = [10,2,-5]
    Output: [10]
*/

import java.util.Arrays;
import java.util.Stack;

class Solution {

    public static int[] asteroidCollision(int[] asteroids) {

        // this stack will hold all surviving asteroids
        Stack<Integer> survivingAsteroids = new Stack<Integer>();

        for (int asteroid : asteroids) {

            // if current asteroid is moving right, push it to top of stack
            if (asteroid > 0) {
                survivingAsteroids.push(asteroid);
            }
            // if current asteroid is moving left...
            else {

                // destroy asteroids from top of stack that are moving right and smaller than current asteroid
                while (!survivingAsteroids.isEmpty() && survivingAsteroids.peek() > 0 && survivingAsteroids.peek() < -asteroid) {
                    survivingAsteroids.pop();
                }

                // if there are no asteroids left, or we found another left moving asteroid, we can push the current asteroid to the top of the stack
                if (survivingAsteroids.isEmpty() || survivingAsteroids.peek() < 0) {
                    survivingAsteroids.push(asteroid);
                }

                // if the asteroid at the top of the stack is the same size moving right, both are destroyed
                if (survivingAsteroids.peek() == -asteroid) {
                    survivingAsteroids.pop();
                }
            }
        }

        // turn results into an array, with the bottom of the stack being the first index in the array
        int[] results = new int[survivingAsteroids.size()];
        int i = survivingAsteroids.size() - 1;
        while (!survivingAsteroids.isEmpty()) {
            results[i] = survivingAsteroids.pop();
            i--;
        }
        return results;
    }

    public static void main(String[] args) {

        int[] asteroids = {10,2,-5,-12};
        int[] result = asteroidCollision(asteroids);

        System.out.println("result: " + Arrays.toString(result));
    }
}