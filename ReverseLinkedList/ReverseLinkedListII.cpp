/*
LeetCode 92. Reverse Linked List II

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example
	Input: head = [1,2,3,4,5], left = 2, right = 4
	Output: [1,4,3,2,5]
*/

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {

	// deal with empty list or lists that don't need any work
	if (head == nullptr || left == right) {
		return head;
	}

	// create dummy node that goes before the head
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* prev = dummy;

	// go to the node right before leftNode
	for (int i = 0; i < left - 1; i++) {
		prev = prev->next;
	}

	// current now points to the leftNode
	// prev will be the node to the left of leftNode
	ListNode* current = prev->next;
	for (int i = 0; i < right - left; i++) {

		// get node to the right of leftNode
		ListNode* nextCopy = current->next;

		// current now points 2 nodes ahead
		current->next = nextCopy->next;

		// flip the direction of nodes around current (current and prev do not change)
		nextCopy->next = prev->next;
		prev->next = nextCopy;
	}

	return dummy->next;
}

void printList(ListNode* head) {
	cout << "printing list: \n";
	ListNode* current = head;
	while (current) {
		cout << current->val << " ";
		current = current->next;
	}
	cout << endl;
}

int main() {

	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	printList(head);
	reverseBetween(head, 2, 4);
	printList(head);


	return 0;
}