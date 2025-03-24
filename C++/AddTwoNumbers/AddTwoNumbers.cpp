/*
LeetCode 2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1
	Input: l1 = [2,4,3], l2 = [5,6,4]
	Output: [7,0,8]
	Explanation: 342 + 465 = 807.
*/

#include <iostream>
#include <cmath>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* node) {
	while (node != nullptr) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}

int nodeToInt(ListNode* root) {

	int nodeInt = 0;
	int place = 0;
	ListNode* current = root;
	while (current != nullptr) {
		nodeInt += current->val * pow(10, place);
		current = current->next;
		place++;
	}

	return nodeInt;
}

ListNode* intToNode(int num) {

	if (num == 0) {
		return new ListNode(0);
	}

	ListNode* root = nullptr;
	ListNode* current = nullptr;

	while (num > 0) {

		int digit = num % 10;
		num = num / 10;

		if (root == nullptr) {
			root = new ListNode(digit);
			current = root;
		}
		else {
			current->next = new ListNode(digit);
			current = current->next;
		}
	}

	return root;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	int l1Num = nodeToInt(l1);
	int l2Num = nodeToInt(l2);
	int sum = l1Num + l2Num;
	cout << "_sum: " << sum << endl;
	ListNode* rootSum = intToNode(sum);
	return rootSum;
}

int main() {

	/*
	ListNode* root1 = new ListNode(2);
	root1->next = new ListNode(4);
	root1->next->next = new ListNode(3);
	cout << "list1: ";
	printList(root1);

	ListNode* root2 = new ListNode(5);
	root2->next = new ListNode(6);
	root2->next->next = new ListNode(4);
	cout << "list2: ";
	printList(root2);
	*/
	ListNode* root1 = new ListNode(0);
	cout << "list1: ";
	printList(root1);
	ListNode* root2 = new ListNode(0);
	cout << "list2: ";
	printList(root2);

	ListNode* result = addTwoNumbers(root1, root2);
	cout << "sum: ";
	printList(result);
	
	return 0;
}

