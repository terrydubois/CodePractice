/*
LeetCode 61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.

Example 1
    Input: head = [1,2,3,4,5], k = 2
    Output: [4,5,1,2,3]

Example 2
    Input: head = [0,1,2], k = 4
    Output: [2,0,1]
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

ListNode* rotateRightOnce(ListNode* head) {

    // find last node
    ListNode* lastNode = head;
    while (lastNode->next) {
        lastNode = lastNode->next;
    }

    // find second to last node
    ListNode* secondToLastNode = head;
    while (secondToLastNode->next != lastNode) {
        secondToLastNode = secondToLastNode->next;
    }

    // lastNode becomes the new first node, and secondToLastNode becomes the last node
    lastNode->next = head;
    secondToLastNode->next = nullptr;
    return lastNode;
}

int getLen(ListNode* head) {
    int len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    return len;
}

ListNode* rotateRight(ListNode* head, int k) {

    // deal with cases where list is no more than 1 node
    if (head == nullptr || head->next == nullptr) return head;

    // find minimal number of rotations that need to be done
    int len = getLen(head);
    int rotations = k % len;

    // rotate that many times
    for (int i = 0; i < rotations; i++) {
        head = rotateRightOnce(head);
    }
    return head;
}

void printList(ListNode* head) {
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

    cout << "input: ";
    printList(head);

    ListNode* headRotated = rotateRight(head, 2);
    cout << "output: ";
    printList(headRotated);

    return 0;
}