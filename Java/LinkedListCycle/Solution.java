/*
LeetCode 141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

Example
    Input: head = [3,2,0,-4], pos = 1
    Output: true
*/

import java.util.HashSet;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {

    public static boolean hasCycle(ListNode head) {

        HashSet<ListNode> nodes = new HashSet<ListNode>();
        while (head != null) {
            if (nodes.contains(head)) {
                return true;
            }
            nodes.add(head);
            head = head.next;
        }
        return false;
    }

    public static void main(String[] args) {

        ListNode head = new ListNode(3);
        head.next = new ListNode(2);
        head.next.next = new ListNode(0);
        head.next.next.next = new ListNode(-4);
        head.next.next.next.next = head.next;
        printList(head);

        boolean output = hasCycle(head);
        System.out.println("output: " + output);
    }
}