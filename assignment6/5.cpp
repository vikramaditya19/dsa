#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

bool isCircular(Node* head) {
    if (head == NULL)
        return false;       // empty list is NOT circular here

    Node* temp = head->next;

    // Traverse until NULL or back to head
    while (temp != NULL && temp != head)
        temp = temp->next;

    if (temp == head)
        return true;        // came back to head → circular

    return false;           // reached NULL → not circular
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->next = third;
    third->next = head;   // Make it circular

    if (isCircular(head))
        cout << "It is a Circular Linked List.";
    else
        cout << "It is NOT a Circular Linked List.";

    return 0;
}
