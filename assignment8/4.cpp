#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Utility function to check BST using min/max range
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

// Main function to check if tree is BST
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Sample tree for testing
int main() {
    /*
            10
           /  \
          5   20
             /  \
            15  25
    */

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    if (isBST(root))
        cout << "The given tree is a BST\n";
    else
        cout << "The given tree is NOT a BST\n";

    return 0;
}
