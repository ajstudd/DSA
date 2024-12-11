#include <iostream>
#include <queue>
using namespace std;

// Definition of a Binary Tree Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the binary tree (internal handling)
void insertNode(TreeNode *&root, int val)
{
    TreeNode *newNode = new TreeNode(val); // Create a new node with the given value

    // If the tree is empty, make the new node the root
    if (!root)
    {
        root = newNode;
        return;
    }

    // Use a queue to perform level-order traversal and find the first available position
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();

        // Check for the left child
        if (!current->left)
        {
            current->left = newNode;
            return;
        }
        else
        {
            q.push(current->left);
        }

        // Check for the right child
        if (!current->right)
        {
            current->right = newNode;
            return;
        }
        else
        {
            q.push(current->right);
        }
    }
}

// Function to perform level-order traversal of the tree
void levelOrderTraversal(TreeNode *root)
{
    if (!root)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();

        cout << current->val << " "; // Print the current node's value

        // Enqueue left and right children if they exist
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
    cout << endl;
}

int main()
{
    TreeNode *root = nullptr;

    // Insert nodes into the binary tree
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);

    // Display the tree using level-order traversal
    cout << "Level-order Traversal after Insertion: ";
    levelOrderTraversal(root);

    return 0;
}
