import java.util.Arrays;

class Solution {

    public static int findMinArrowShots(int[][] points) {

        // start by sorting balloons based on their leftmost point
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));

        // the result will be at most the total number of balloons
        int minArrows = points.length;

        for (int i = 0; i < points.length - 1; i++) {

            // get current and next balloons
            int[] curBalloon = points[i];
            int[] nextBalloon = points[i + 1];

            // check if next balloon overlaps with current balloon
            if (nextBalloon[0] <= curBalloon[1]) {

                // if it does, we need one less arrow
                minArrows--;
                
                // but we also need to merge the balloons so that we are only evaluating the area that they overlap
                nextBalloon[1] = Math.min(curBalloon[1], nextBalloon[1]);
            }
        }

        return minArrows;
    }

    public static void main(String[] args) {
        int[][] input = {
            {10, 16},
            {2, 8},
            {1, 6},
            {7, 12}
            
        };
        int output = findMinArrowShots(input);
        System.out.println("result: " + output);
    }
}