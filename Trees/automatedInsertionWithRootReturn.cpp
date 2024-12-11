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

// Function to insert a node in the binary tree (level-order insertion)
TreeNode *insertNode(TreeNode *root, int val)
{
    TreeNode *newNode = new TreeNode(val); // Create a new node with the given value

    // If the tree is empty, the new node becomes the root
    if (!root)
        return newNode;

    // Use a queue to traverse the tree in level order
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();

        // If the left child is missing, insert the new node there
        if (!current->left)
        {
            current->left = newNode;
            break;
        }
        else
        {
            q.push(current->left);
        }

        // If the right child is missing, insert the new node there
        if (!current->right)
        {
            current->right = newNode;
            break;
        }
        else
        {
            q.push(current->right);
        }
    }

    return root;
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

        // Add left and right children to the queue if they exist
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
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 7);

    // Display the tree using level-order traversal
    cout << "Level-order Traversal after Insertion: ";
    levelOrderTraversal(root);

    return 0;
}
