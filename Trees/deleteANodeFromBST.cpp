#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *findMinimumInRight(TreeNode *root)
    {
        if (!root->left)
        {
            return root;
        }
        return (findMinimumInRight(root->left));
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            // Node to be deleted found

            // Case 1: No child
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }

            // Case 2: One child
            if (!root->left)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            TreeNode *minNode = findMinimumInRight(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }
};

void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

TreeNode *buildTestTree()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(7);
    return root;
}

int main()
{
    Solution sol;
    TreeNode *root = buildTestTree();

    cout << "Original tree (inorder): ";
    inorder(root);
    cout << endl;

    int key = 3;
    TreeNode *preservedRoot = root;
    root = sol.deleteNode(root, key);

    cout << "Tree after deleting " << key << " (inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
