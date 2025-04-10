/*
LeetCode 530. Minimum Absolute Difference in BST

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Example
    Input: root = [4,2,6,1,3]
    Output: 1
*/
#include <iostream>
#include <climits>
#include <vector>

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

void traverseTree(TreeNode* root, vector<int>& nodeValues) {

    // stop if find end of branch
    if (root == nullptr) return;

    // traverse the tree in-order: left, current, right
    traverseTree(root->left, nodeValues);
    nodeValues.push_back(root->val);
    traverseTree(root->right, nodeValues);
}

int getMinimumDifference(TreeNode* root) {
    
    // traverse the tree to fill a list with every node value
    // the list will naturally be sorted because we are traversing a BST in-order
    vector<int> nodeValues;
    traverseTree(root, nodeValues);

    // find the minimum absolute difference across all adjacent pairs of values
    int minDiff = INT_MAX;
    for (int i = 1; i < nodeValues.size(); i++) {
        minDiff = min(minDiff, abs(nodeValues[i] - nodeValues[i - 1]));
    }
    return minDiff;
}

int main() {

    TreeNode* root = new TreeNode(236);
    root->left = new TreeNode(104);
    root->right = new TreeNode(701);
    root->left->right = new TreeNode(227);
    root->right->right = new TreeNode(911);

    int result = getMinimumDifference(root);
    cout << "result: " << result << endl;

    return 0;
}