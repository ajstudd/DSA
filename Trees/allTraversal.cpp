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

// Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(TreeNode *root)
{
    if (!root)
        return;                    // Base case: If node is null, return
    inorderTraversal(root->left);  // Visit left subtree
    cout << root->val << " ";      // Visit root
    inorderTraversal(root->right); // Visit right subtree
}

// Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(TreeNode *root)
{
    if (!root)
        return;                     // Base case: If node is null, return
    cout << root->val << " ";       // Visit root
    preorderTraversal(root->left);  // Visit left subtree
    preorderTraversal(root->right); // Visit right subtree
}

// Postorder Traversal (Left -> Right -> Root)
void postorderTraversal(TreeNode *root)
{
    if (!root)
        return;                      // Base case: If node is null, return
    postorderTraversal(root->left);  // Visit left subtree
    postorderTraversal(root->right); // Visit right subtree
    cout << root->val << " ";        // Visit root
}

// Level-order Traversal (Breadth-First Search)
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

        cout << current->val << " ";

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}

// my attempt , incorrect
// void levelOrderTraversal(TreeNode *root)
// {
//     if (!root)
//         return;

//     queue<TreeNode *> q;

//     if (root->left)
//     {
//         q.push(root->left);
//     }
//     if (root->right)
//     {
//         q.push(root->right);
//     }
//     cout << root->val;

//     while (!q.empty())
//     {
//         levelOrderTraversal(q.front());
//         q.pop();
//     }
// }

int main()
{
    // Constructing a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Display all types of traversals
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Level-order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
