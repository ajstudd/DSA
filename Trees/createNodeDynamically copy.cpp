#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the BST
// I think BST was made so that insertion of nodes can be automated as the direction is known
Node *insertNode(Node *root, int val)
{
    if (root == nullptr) // If the tree/subtree is empty, create a new node
        return new Node(val);

    if (val < root->data)
        root->left = insertNode(root->left, val); // Insert in the left subtree
    else
        root->right = insertNode(root->right, val); // Insert in the right subtree

    return root; // Return the unchanged root node
}

// Function to perform inorder traversal
void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);  // Visit left subtree
    cout << root->data << " ";     // Visit current node
    inorderTraversal(root->right); // Visit right subtree
}

int main()
{
    Node *root = nullptr; // Initialize the root as null

    // Dynamically insert nodes
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 8);

    // Perform inorder traversal
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
