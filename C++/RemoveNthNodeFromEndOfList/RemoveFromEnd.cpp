/*
LeetCode 19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]
*/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {

    // create a dummy node to the left of head
    ListNode* dummy = new ListNode(0, head);
    ListNode* result = dummy;

    // move head to the right n steps, to make a gap of n nodes between dummy and head
    for (int i = 0; i < n; i++) {
        head = head->next;
    }

    // move both pointers to the right until head reaches the end, so now dummy is nth from the end
    while (head) {
        head = head->next;
        dummy = dummy->next;
    }

    // dummy should now skip a node
    dummy->next = dummy->next->next;

    // return head node, which might have changed
    return result->next;
}

void printList(ListNode* head) {
    cout << "list: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    cout << "before removing\n";
    printList(head);

    ListNode* headAfterRemoving = removeNthFromEnd(head, 2);
    cout << "after removing\n";
    printList(head);

    return 0;
}