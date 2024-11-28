#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal
void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);  // Visit left subtree
    cout << root->data << " ";     // Visit current node
    inorderTraversal(root->right); // Visit right subtree
}
void preorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";     // Visit current node
    inorderTraversal(root->left);  // Visit left subtree
    inorderTraversal(root->right); // Visit right subtree
}
void postorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);  // Visit left subtree
    inorderTraversal(root->right); // Visit right subtree
    cout << root->data << " ";     // Visit current node
}

int main()
{
    // Creating nodes manually
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(8);

    // Performing inorder traversal
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    cout << "Pre Order Traversal: ";
    preorderTraversal(root);
    cout << endl;
    cout << "Post Order Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
