/*
LeetCode 226. Invert Binary Tree

Given the root of a binary tree, invert the tree, and return its root.

Example 1
	Input: root = [4,2,7,1,3,6,9]
	Output: [4,7,2,9,6,3,1]

Example 2
	Input: root = [2,1,3]
	Output: [2,3,1]
*/

#include <iostream>
#include <queue>

using namespace std;

// definition for a binary tree node
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void levelOrderTraversal(TreeNode* root) {

	// create queue of TreeNode*
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {

		// pop first node in queue and visit it
		TreeNode* current = q.front();
		q.pop();
		cout << current->val << " ";

		// if current node has children, queue them up
		if (current->left != nullptr) {
			q.push(current->left);
		}
		if (current->right != nullptr) {
			q.push(current->right);
		}
	}
	cout << endl;
}

TreeNode* invertTree(TreeNode* root) {

	// stop recursing once we reach nullptr
	if (root == nullptr) return root;

	// swap left and right children
	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;

	// recurse down to invert children's children
	invertTree(root->left);
	invertTree(root->right);

	return root;
}

int main() {


	// create example tree
	TreeNode* root = new TreeNode(4);

	root->left = new TreeNode(2);
	root->right = new TreeNode(7);

	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);

	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	cout << "original:\n";
	levelOrderTraversal(root);

	root = invertTree(root);
	cout << "inverted:\n";
	levelOrderTraversal(root);

	return 0;
}