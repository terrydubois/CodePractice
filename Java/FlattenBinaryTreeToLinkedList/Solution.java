import java.util.LinkedList;
import java.util.Queue;

// Definition for a binary tree node
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

    public static void printTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode curNode = queue.poll();
            System.out.print(curNode.val + " ");
            if (curNode.left != null) queue.add(curNode.left);
            if (curNode.right != null) queue.add(curNode.right);
        }
        System.out.println();
    }

    public static TreeNode dfs(TreeNode root) {

        if (root == null) return null;

        // recurse down left and right subtrees, going down left first
        TreeNode leftTail = dfs(root.left);
        TreeNode rightTail = dfs(root.right);

        // is we have a leftTail, then we can connect this into our tree on the right
        if (leftTail != null) {

            // leftTail's right should now point to root's right, so the tail of the list is connected
            leftTail.right = root.right;
            
            // root should now connect to the left subtree on the right side
            root.right = root.left;

            // the root should not point to anything on the left anymore, as we have moved all of the left subtrees contents to the right
            root.left = null;
        }

        // return whatever node we can, prioritizing right, then left, then root
        if (rightTail != null) return rightTail;
        else if (leftTail != null) return leftTail;
        return root;
    }

    public static void flatten(TreeNode root) {
        dfs(root);
    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(5);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.right = new TreeNode(6);

        System.out.println("input: ");
        printTree(root);

        flatten(root);
        System.out.println("output: ");
        printTree(root);
    }
}