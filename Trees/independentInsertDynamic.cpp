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
void insertNode(Node *&root, int val)
{
    if (root == nullptr)
    {
        root = new Node(val); // Create a new node if the subtree is empty
        return;
    }

    if (val < root->data)
        insertNode(root->left, val); // Insert in the left subtree
    else
        insertNode(root->right, val); // Insert in the right subtree
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
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 8);

    // Perform inorder traversal
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
