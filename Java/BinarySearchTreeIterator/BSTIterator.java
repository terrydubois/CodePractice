import java.util.Stack;

// Definition for a binary tree node.
public class TreeNode {
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

class BSTIterator {

    // use a stack for iterative DFS traversal of tree
    Stack<TreeNode> stack = new Stack<TreeNode>();

    private void pushLeftNodes(TreeNode node) {

        // go down the tree, pushing current node's left child to the stack
        while (node != null) {
            stack.push(node);
            node = node.left;
        }
    }

    public BSTIterator(TreeNode root) {
        // on instantiation, push the root's left nodes
        pushLeftNodes(root);
    }

    public int next() {

        // next node will be on top of the stack
        TreeNode nextNode = stack.pop();

        // go to the next node's right child, and push that node's left children
        pushLeftNodes(nextNode.right);

        // return next node's value
        return nextNode.val;
    }

    public boolean hasNext() {

        // if the stack is empty, there is no next value
        return !stack.empty();
    }
}