/*
LeetCode 222. Count Complete Tree Nodes

Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.

Example
    Input: root = [1,2,3,4,5,6]
    Output: 6
*/

#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void levelOrderTraversal(TreeNode* root) {

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
    cout << endl;
}

int countNodes(TreeNode* root) {

    // stop recursing once we reach nullptr
    if (root == nullptr) return 0;

    // recurse down for left and right children
    int result = 0;
    int left = countNodes(root->left);
    int right = countNodes(root->right);

    // add one to count for current node
    return 1 + left + right;
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    levelOrderTraversal(root);

    cout << "count: " << countNodes(root) << endl;

    return 0;
}