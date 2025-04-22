import java.util.ArrayList;
import java.util.List;
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

class Solution {

    public static List<Integer> rightSideView(TreeNode root) {

        // results will be stored in this list
        List<Integer> rightVals = new ArrayList<Integer>();

        // create a queue to do BFS
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {

            TreeNode rightNode = null;

            // at the start of this loop, queue's length contains all of the nodes at this level
            int queueLen = queue.size();

            // use a for loop (instead of a while) because queue's size will be changing throughout this loop
            for (int i = 0; i < queueLen; i++) {

                // get node from front of queue
                TreeNode node = queue.poll();
                if (node != null) {

                    // once this for loop is complete, rightNode will be the rightmost node of its level
                    rightNode = node;

                    // add this node's left and right children to queue (queueing up next level)
                    queue.add(node.left);
                    queue.add(node.right);
                }
            }

            // now that we have found rightNode, add its value to our results list
            if (rightNode != null) rightVals.add(rightNode.val);
        }

        return rightVals;
    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.right = new TreeNode(5);
        root.right.right = new TreeNode(4);
        root.left.right.left = new TreeNode(6);

        List<Integer> output = rightSideView(root);
        System.out.println("result: " + output.toString());
    }
}