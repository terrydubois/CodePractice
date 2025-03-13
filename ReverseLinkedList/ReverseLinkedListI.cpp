/*
LeetCode 206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example
    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]
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

ListNode* reverseList(ListNode* head) {

    // keep a pointer to prev and current nodes
    ListNode* prev = nullptr;
    ListNode* current = head;

    // loop through the list
    while (current) {
        
        // save a copy of current->next, because we overwrite it to be prev
        ListNode* next = current->next;
        current->next = prev;

        // use our copy of current->next to progress through list
        prev = current;
        current = next;
    }

    // prev is now the last item in the original list
    return prev;
}

void printList(ListNode* head) {
    cout << "list: ";
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
    cout << "reversing...\n";
    ListNode* newHead = reverseList(head);
    printList(newHead);

    return 0;
}