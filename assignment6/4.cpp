#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    void insert(char val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    bool isPalindrome() {
        if (head == NULL) return true;

        Node* left = head;
        Node* right = tail;

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }

        return true;
    }
};

int main() {
    DoublyList dl;

    dl.insert('R');
    dl.insert('A');
    dl.insert('D');
    dl.insert('A');
    dl.insert('R');

    if (dl.isPalindrome())
        cout << "The list is a palindrome.";
    else
        cout << "The list is NOT a palindrome.";

    return 0;
}
