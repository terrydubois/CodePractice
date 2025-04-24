public class Solution {

    public static int searchReg(int[] nums, int target) {
        int l = 0;
        int r = nums.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }

    public static int searchRotated(int[] nums, int target) {
        int l = 0;
        int r = nums.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            
            if (nums[l] < nums[mid]) {
                // left subarray is sorted

                // check if target is in left subarrary
                if (target >= nums[l] && target <= nums[mid]) r = mid - 1;
                else l = mid + 1;
            }
            else {
                // right half is sorted
                
                // check if target is in right subarrary
                if (target >= nums[mid] && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }

    public static void searchAll(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int target = nums[i];
            int result = searchRotated(nums, target);
            System.out.println("found " + target + " at index " + result);
        }
    }

    public static void main(String[] args) {
        int[] nums = {4,5,6,7,0,1,2};
        searchAll(nums);
    }
}