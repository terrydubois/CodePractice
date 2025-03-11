/*
LeetCode 138. Copy List with Random Pointer



*/

#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {

    // map each original node to a new node
    unordered_map<Node*, Node*> map;
    Node* current = head;
    while (current) {

        // new node is created with same val as current node
        map[current] = new Node(current->val);
        current = current->next;
    }

    // our new nodes do not have their next or random members assigned yet, so let's do that
    current = head;
    while (current) {
        // use the mapped versions of next and random
        Node* copy = map[current];
        copy->next = map[current->next];
        copy->random = map[current->random];
        current = current->next;
    }

    return map[head];
}

// function to print list contents
void printList(Node* head) {
    cout << "printing list...\n";
    while (head != nullptr) {
        cout << "val: " << head->val << ", random: ";
        if (head->random == nullptr) cout << nullptr;
        else cout << head->random->val;
        cout << endl;
        head = head->next;
    }
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = nullptr;

    Node* headCopy = copyRandomList(head);

    printList(head);
    printList(headCopy);

    return 0;
}