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

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    // Recursive Preorder Traversal
    void preorder(Node* node) {
        if (node == NULL) return;

        cout << node->data << " ";   // Visit root
        preorder(node->left);        // Left subtree
        preorder(node->right);       // Right subtree
    }

    // Recursive Inorder Traversal
    void inorder(Node* node) {
        if (node == NULL) return;

        inorder(node->left);         // Left subtree
        cout << node->data << " ";   // Visit root
        inorder(node->right);        // Right subtree
    }

    // Recursive Postorder Traversal
    void postorder(Node* node) {
        if (node == NULL) return;

        postorder(node->left);       // Left subtree
        postorder(node->right);      // Right subtree
        cout << node->data << " ";   // Visit root
    }
};

int main() {

    BinaryTree bt;

    // Creating a sample tree manually:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    bt.root = new Node(1);
    bt.root->left = new Node(2);
    bt.root->right = new Node(3);
    bt.root->left->left = new Node(4);
    bt.root->left->right = new Node(5);

    cout << "Preorder Traversal: ";
    bt.preorder(bt.root);

    cout << "\nInorder Traversal: ";
    bt.inorder(bt.root);

    cout << "\nPostorder Traversal: ";
    bt.postorder(bt.root);

    return 0;
}
