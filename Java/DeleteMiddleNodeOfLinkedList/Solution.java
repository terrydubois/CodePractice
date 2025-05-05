/*
LeetCode 2095. Delete the Middle Node of a Linked List

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

Example 1
    Input: head = [1,3,4,7,1,2,6]
    Output: [1,3,4,1,2,6]

Example 2
    Input: head = [1,2,3,4]
    Output: [1,2,4]
*/

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }

    void printList() {
        ListNode cur = this;
        while (cur != null) {
            System.out.print(cur.val + " ");
            cur = cur.next;
        }
        System.out.println();
    }
}

class Solution {

    public static ListNode deleteMiddle(ListNode head) {
        
        // calculate size of list
        int size = 0;
        ListNode cur = head;
        while (cur != null) {
            size++;
            cur = cur.next;
        }

        // lists with <= 1 nodes will just be entirely deleted
        if (size <= 1) {
            return null;
        }

        // loop through the list to find the middle node
        int middle = size / 2;
        int index = 0;
        ListNode prev = null;
        cur = head;
        while (cur != null) {

            // found middle node
            if (index == middle) {

                // connect prev node to next node
                if (prev != null) {
                    prev.next = cur.next;
                }

                // don't need to loop any further
                break;
            }

            // continue on with loop
            index++;
            prev = cur;
            cur = cur.next;
        }

        return head;
    }

    public static void main(String[] args) {
        
        ListNode head = new ListNode(1);
        head.next = new ListNode(3);
        head.next.next = new ListNode(4);
        head.next.next.next = new ListNode(7);
        head.next.next.next.next = new ListNode(1);
        head.next.next.next.next.next = new ListNode(2);
        head.next.next.next.next.next.next = new ListNode(6);

        System.out.println("Before");
        head.printList();

        head = deleteMiddle(head);

        System.out.println("After");
        head.printList();
    }
}