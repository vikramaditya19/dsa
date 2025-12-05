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

    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // circular
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        cout << "Circular List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        // print head value again
        cout << head->data << " (head repeated)";
        cout << endl;
    }
};

int main() {
    CircularList cl;
    cl.insert(10);
    cl.insert(20);
    cl.insert(30);
    cl.insert(40);

    cl.display();

    return 0;
}
