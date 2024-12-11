#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *findLCA(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q)
        return root;

    TreeNode *left = findLCA(root->left, p, q);
    TreeNode *right = findLCA(root->right, p, q);

    if (left && right)
        return root;            // Both nodes found in different subtrees
    return left ? left : right; // One node found
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *p = root->left->left;  // Node 5
    TreeNode *q = root->left->right; // Node 1

    TreeNode *lca = findLCA(root, p, q);
    if (lca)
        cout << "LCA: " << lca->val << endl;
    else
        cout << "No LCA found." << endl;

    return 0;
}
