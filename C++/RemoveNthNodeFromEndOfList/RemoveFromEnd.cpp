/*
LeetCode 19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]
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

ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* res = new ListNode(0);
    res->next = head;
    ListNode* dummy = res;

    return head;
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

    cout << "hello\n";

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);

    cout << "before removing\n";
    printList(head);

    ListNode* headAfterRemoving = removeNthFromEnd(head, 2);
    cout << "after removing\n";
    printList(head);

    return 0;
}