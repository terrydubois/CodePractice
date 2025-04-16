/*
LeetCode 108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1
    Input: nums = [-10,-3,0,5,9]
    Output: [0,-3,9,-10,null,5]
*/

import java.util.LinkedList;
import java.util.Queue;

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution {

    public static void printTree(TreeNode head) {

        Queue<TreeNode> q = new LinkedList<>();
        q.add(head);

        TreeNode qPoll = q.poll();
        while (qPoll != null) {

            System.out.print(qPoll.val + " ");
            if (qPoll.left != null) q.add(qPoll.left);
            if (qPoll.right != null) q.add(qPoll.right);

            qPoll = q.poll();
        }
        System.out.println();
    }

    public static TreeNode createBST(int[] nums, int l, int r) {

        // base case once search space has been narrowed entirely
        if (l > r) return null;

        // find midpoint of sorted array, which will be the current root
        int mid = (l + r) / 2;
        TreeNode node = new TreeNode(nums[mid]);

        // use recursive BST technique to narrow down search space with sorted array
        node.left = createBST(nums, l, mid - 1);
        node.right = createBST(nums, mid + 1, r);
        return node;
    }

    public static TreeNode sortedArrayToBST(int[] nums) {

        // the root will be the midpoint of the entire array
        // that root's left leaf will be the midpoint of the left subarray
        // and the right leaf will be the midpoint of the right subarray
        return createBST(nums, 0, nums.length - 1);
    }

    public static void main(String[] args) {

        int[] input = {-10,-3,0,5,9};
        TreeNode output = sortedArrayToBST(input);

        System.out.println("Result:");
        printTree(output);
    }
}