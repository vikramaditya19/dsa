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

class CircularList {
    Node* head;

public:
    CircularList() {
        head = NULL;
    }

    // INSERTION
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;

            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int val) {
        Node* temp = head;

        if (head == NULL) return;

        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Key not found!\n";
    }

    // DELETION
    void deleteNode(int key) {
        if (head == NULL) {
            cout << "Empty list\n";
            return;
        }

        Node *curr = head, *prev = NULL;

        // deleting head node
        if (head->data == key) {
            Node* temp = head;

            // only one node
            if (head->next == head) {
                head = NULL;
                delete temp;
                return;
            }

            // find last node
            while (temp->next != head)
                temp = temp->next;

            temp->next = head->next;
            temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // delete in middle/end
        do {
            prev = curr;
            curr = curr->next;

            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                return;
            }
        } while (curr != head);

        cout << "Node not found\n";
    }

    // SEARCH
    void search(int key) {
        if (head == NULL) {
            cout << "List empty\n";
            return;
        }

        Node* temp = head;
        int pos = 1;

        do {
            if (temp->data == key) {
