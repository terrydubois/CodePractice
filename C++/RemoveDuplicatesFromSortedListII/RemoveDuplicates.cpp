/*

LeetCode 82. Remove Duplicates From Sorted List II

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1
    Input: head = [1,2,3,3,4,4,5]
    Output: [1,2,5]

Example 2
    Input: head = [1,1,1,2,3]
    Output: [2,3]
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

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* deleteDuplicates(ListNode* head) {

    // if list is 0 or 1 nodes, just return the list as is
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // create a dummy node for cases where list starts with duplicates
    ListNode* dummy = new ListNode(0, head);
    ListNode* cur = head;
    ListNode* prev = dummy;

    while (cur) {

        // if there is a next node, and that next node's val is equal to this node's val, we need to remove duplicates
        if (cur->next && cur->val == cur->next->val) {

            // keep going until we find a node with a unique value, or until we reach the end of the list
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }

            // now that we have found a unique value (or nullptr), connect the prev node to this one's next, skipping all duplicates
            prev->next = cur->next;
        }
        else {

            // if we didn't find a duplicate, our prev pointer can continue along the list normally
            prev = cur;
        }

        // cur pointer continues along list
        cur = cur->next;
    }
    
    // dummy points to the head of our new list, which may have changed since the beginning
    return dummy->next;
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    cout << "input:\n";
    printList(head);

    head = deleteDuplicates(head);

    cout << "output:\n";
    printList(head);

    return 0;
}