/*
LeetCode 86. Partition List

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example 1
    Input: head = [1,4,3,2,5,2], x = 3
    Output: [1,2,2,4,3,5]
*/

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) {
        this.val = val;
    }
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class Solution {

    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static ListNode partition(ListNode head, int x) {

        // create two lists for each partition
        // then once the two lists are filled out, merge them

        // start by creating some dummy nodes to hold our new lists
        ListNode leftHead = new ListNode(-1);
        ListNode rightHead = new ListNode(-1);
        ListNode leftCur = leftHead;
        ListNode rightCur = rightHead;

        // loop through original list
        ListNode cur = head;
        while (cur != null) {

            // if current node's val is < x, add to left list
            if (cur.val < x) {
                leftCur.next = cur;
                leftCur = leftCur.next;
            }
            // otherwise, add to right list
            else {
                rightCur.next = cur;
                rightCur = rightCur.next;
            }
            cur = cur.next;
        }

        // connect the last node in the left list to the first node in the right list
        // making sure to skip the dummy nodes
        leftCur.next = rightHead.next;

        // the last node in the right list might still be pointing to some other node, so
        // set its next node to be null
        rightCur.next = null;

        return leftHead.next;
    }

    public static void main(String[] args) {

        ListNode head = new ListNode(1);
        head.next = new ListNode(4);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(2);
        head.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next = new ListNode(2);
        System.out.println("input: ");
        printList(head);

        head = partition(head, 3);

        System.out.println("output: ");
        printList(head);
    }
}