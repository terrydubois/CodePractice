import java.util.HashMap;

class Solution {

    public static int maxOperations(int[] nums, int k) {
        
        int pairs = 0;
        HashMap<Integer, Integer> numCounts = new HashMap<Integer, Integer>();

        for (int n : nums) {

            // check if compliment appears in numCounts
            int compliment = k - n;
            int complimentCount = 0;
            if (numCounts.containsKey(compliment)) complimentCount = numCounts.get(compliment);

            if (complimentCount >= 1) {
                pairs++;
                numCounts.put(compliment, complimentCount - 1);
            }
            else {
                int numCount = 0;
                if (numCounts.containsKey(n)) numCount = numCounts.get(n);
                numCounts.put(n, numCount + 1);
            }
        }

        return pairs;
    }

    public static void main(String[] args) {

        /*
            2: 1
        */

        int[] nums = {2,2,2,3,1,1,4,1};
        int k = 4;
        int result = maxOperations(nums, k);
        System.out.println("result: " + result);
    }
}