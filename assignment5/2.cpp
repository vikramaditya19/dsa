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
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Count occurrences of key
    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }

        return count;
    }

    // Delete all occurrences of key
    void deleteAll(int key) {
        // Delete from beginning while matches
        while (head != NULL && head->data == key) {
            Node* temp = head;
            h
