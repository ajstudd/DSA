#include <iostream>
using namespace std;

// Define a node of the BST
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to find the minimum value node in a subtree
TreeNode *findMin(TreeNode *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

// Function to delete a node in a BST
TreeNode *deleteNode(TreeNode *root, int key)
{
    // Base case: if the tree is empty
    if (root == nullptr)
    {
        return root;
    }

    // Step 1: Traverse the tree to find the node to delete
    if (key < root->val)
    {
        root->left = deleteNode(root->left, key); // Search in the left subtree
    }
    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key); // Search in the right subtree
    }
    else
    {
        // Step 2: Node to delete found

        // Case 1: Node has no children (leaf node)
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // Case 2: Node has one child
        else if (root->left == nullptr)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has two children
        else
        {
            TreeNode *temp = findMin(root->right);            // Find in-order successor
            root->val = temp->val;                            // Replace value with successor's value
            root->right = deleteNode(root->right, temp->val); // Delete the successor
        }
    }
    return root;
}

// Function to print the tree in-order
void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Function to insert a node into the BST
TreeNode *insertNode(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }

    if (value < root->val)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->val)
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Main function
int main()
{
    TreeNode *root = nullptr;

    // Insert nodes into the BST
    root = insertNode(root, 40);
    root = insertNode(root, 8);
    root = insertNode(root, 115);
    root = insertNode(root, 4);
    root = insertNode(root, 11);
    root = insertNode(root, 95);
    root = insertNode(root, 120);
    root = insertNode(root, 10);
    root = insertNode(root, 12);
    root = insertNode(root, 45);
    root = insertNode(root, 114);
    root = insertNode(root, 130);

    cout << "In-order before deletion: ";
    inorderTraversal(root);
    cout << endl;

    int key = 115;
    root = deleteNode(root, key);

    cout << "In-order after deleting " << key << ": ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
