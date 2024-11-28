// INFO: My partially complete logic code
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void inOrderTraversal(bool &isSame, TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q != nullptr)
        {
            isSame = false;
            return;
        }
        else if (p == nullptr && q == nullptr)
        {
            return;
        }
        else
        {
            if (p->val != q->val)
            {
                isSame = false;
                return;
            }
            else
            {
                inOrderTraversal(isSame, p->left, q->left);
                inOrderTraversal(isSame, p->right, q->right);
            }
        }
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool isSame = true;
        inOrderTraversal(isSame, p, q);
        return isSame;
    }
};

// INFO: Optimised code with gpt
class Solution
{
public:
    bool inOrderTraversal(TreeNode *p, TreeNode *q)
    {
        // Both nodes are null, so they are the same
        if (p == nullptr && q == nullptr)
            return true;

        // One node is null but the other is not, so they are different
        if (p == nullptr || q == nullptr)
            return false;

        // Check the current node's value
        if (p->val != q->val)
            return false;

        // Recursively check the left and right subtrees
        return inOrderTraversal(p->left, q->left) && inOrderTraversal(p->right, q->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return inOrderTraversal(p, q);
    }
};
