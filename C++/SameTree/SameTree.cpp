/*
LeetCode 100. Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1
    Input: p = [1,2,3], q = [1,2,3]
    Output: true

Example 2
    Input: p = [1,2], q = [1,null,2]
    Output: false

Example 3
    Input: p = [1,2,1], q = [1,1,2]
    Output: false
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

// print tree with level order traversal
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

bool isSameTree(TreeNode* p, TreeNode* q) {

    // if only one of the nodes is nullptr, they are not equal
    if (p != nullptr && q == nullptr) return false;
    if (p == nullptr && q != nullptr) return false;

    // if both are nullptr, we've reached the end of each and haven't found a mismatch
    if (p == nullptr && q == nullptr) return true;

    // if both have values, but are mismatched, they are not equal
    if (p->val != q->val) return false;

    // recurse down to check if child nodes are the same
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    cout << "tree 1:\n";
    levelOrderTraversal(root1);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    cout << "tree 2:\n";
    levelOrderTraversal(root2);

    bool isSame = isSameTree(root1, root2);
    cout << "isSame: " << isSame << endl;

    return 0;
}