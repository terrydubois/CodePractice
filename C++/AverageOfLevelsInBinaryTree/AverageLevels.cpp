/*
LeetCode 637. Average of Levels in Binary Tree

Given the root of a binary tree, return the average value of the nodes on each level in the form of an array.

Example 1
    Input: root = [3,9,20,null,null,15,7]
    Output: [3.00000,14.50000,11.00000]

Example 2
    Input: root = [3,9,20,15,7]
    Output: [3.00000,14.50000,11.00000]
*/

#include <iostream>
#include <vector>
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

void printVec(vector<double>& vec) {
    for (double num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

vector<double> averageOfLevels(TreeNode* root) {

    // create vector of doubles to store averages
    vector<double> averages;
    if (root == nullptr) return averages;

    // create a queue to do BFS
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {

        // at this moment, the queue entirely consists of all nodes on a given level
        int levelSize = q.size();
        double sum = 0;

        // loop through all nodes at this level
        for (int i = 0; i < levelSize; i++) {

            // add current level nodes into sum
            TreeNode* curNode = q.front();
            q.pop();
            sum += curNode->val;

            // queue up nodes on next level
            if (curNode->left != nullptr) q.push(curNode->left);
            if (curNode->right != nullptr) q.push(curNode->right);
        }

        // get the average for this level 
        averages.push_back(sum / levelSize);
    }

    return averages;
}

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<double> results = averageOfLevels(root);
    cout << "results:\n";
    printVec(results);

    return 0;
}