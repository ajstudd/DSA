#include <iostream>
using namespace std;

// Definition of a Binary Search Tree Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the BST (modifies the tree in place)
void insert(TreeNode *&root, int val)
{
    // If the tree is empty, create a new node as the root
    if (!root)
    {
        root = new TreeNode(val);
        return;
    }

    // Traverse the tree to find the appropriate position for the new value
    if (val < root->val)
    {
        // If the value is smaller, move to the left subtree
        insert(root->left, val);
    }
    else
    {
        // If the value is greater or equal, move to the right subtree
        insert(root->right, val);
    }
}

// In-order traversal to display the tree in sorted order
void inOrderTraversal(TreeNode *root)
{
    if (!root)
        return;

    inOrderTraversal(root->left);  // Visit the left subtree
    cout << root->val << " ";      // Print the current node's value
    inOrderTraversal(root->right); // Visit the right subtree
}

int main()
{
    TreeNode *root = nullptr; // Initialize an empty BST

    // Insert values into the BST
    insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Display the BST using in-order traversal
    cout << "In-order Traversal of the BST: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
