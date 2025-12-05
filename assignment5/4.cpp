#include<iostream>
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

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // REVERSE LINKED LIST
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;    // Save next node
            curr->next = prev;    // Reverse link
            prev = curr;          // Move prev ahead
            curr = next;          // Move curr ahead
        }

        // After reversing, prev will be the new head
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    List ll;

    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);

    cout << "Original List: ";
