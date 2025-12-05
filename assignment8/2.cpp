#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // Insert into BST
    Node* insert(Node* node, int val) {
        if (node == NULL)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        return node;
    }

    // ------------------ (a) SEARCH ------------------

    // Recursive Search
    Node* searchRecursive(Node* node, int key) {
        if (node == NULL || node->data == key)
            return node;

        if (key < node->data)
            return searchRecursive(node->left, key);
        else
            return searchRecursive(node->right, key);
    }

    // Non-Recursive Search
    Node* searchIterative(int key) {
        Node* temp = root;

        while (temp != NULL) {
            if (temp->data == key)
                return temp;

            if (key < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return NULL;
    }

    // ------------------ (b) MAXIMUM ------------------

    int maximum(Node* node) {
        if (node == NULL)
            return -1;

        while (node->right != NULL)
            node = node->right;

        return node->data;
    }

    // ------------------ (c) MINIMUM ------------------

    int minimum(Node* node) {
        if (node == NULL)
            return -1;

        while (node->left != NULL)
            node = node->left;

        return node->data;
    }

    // ------------------ (d) INORDER SUCCESSOR ------------------

    Node* inorderSuccessor(Node* root, Node* node) {
        Node* succ = NULL;

        while (root != NULL) {
            if (node->data < root->data) {
                succ = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return succ;
    }

    // ------------------ (e) INORDER PREDECESSOR ------------------

    Node* inorderPredecessor(Node* root, Node* node) {
        Node* pred = NULL;

        while (root != NULL) {
            if (node->data > root->data) {
                pred = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return pred;
    }
};

int main() {
    BST tree;

    // Insert elements
    tree.root = tree.insert(tree.root, 20);
    tree.insert(tree.root, 10);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 15);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 25);
    tree.insert(tree.root, 35);

    // ----------- SEARCH -----------
    int key = 15;
    Node* rec = tree.searchRecursive(tree.root, key);
    Node* iter = tree.searchIterative(key);

    if (rec != NULL) cout << key << " found (recursive)\n";
    else cout << key << " NOT found (recursive)\n";

    if (iter != NULL) cout << key << " found (iterative)\n";
    else cout << key << " NOT found (iterative)\n";

    // ----------- MIN & MAX -----------
    cout << "Minimum element = " << tree.minimum(tree.root) << endl;
    cout << "Maximum element = " << tree.maximum(tree.root) << endl;

    // ----------- SUCCESSOR & PREDECESSOR -----------
    Node* node = tree.searchIterative(15);

    Node* succ = tree.inorderSuccessor(tree.root, node);
    Node* pred = tree.inorderPredecessor(tree.root, node);

    if (succ) cout << "Inorder Successor of 15 = " << succ->data << endl;
    else cout << "No Inorder Successor.\n";

    if (pred) cout << "Inorder Predecessor of 15 = " << pred->data << endl;
    else cout << "No Inorder Predecessor.\n";

    return 0;
}
