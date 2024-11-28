/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// INFO: Initial Solution
class Solution
{
    bool findItem(TreeNode *root, int target, int &reachingDist)
    {
        reachingDist++;
        if (root == NULL)
            return false;
        if (root->val == target)
            return true;
        return findItem(root->left, target, reachingDist) || findItem(root->right, target, reachingDist);
    };
    void findParent(TreeNode *&root, TreeNode *p, TreeNode *q, int lastDist)
    {
        if (root == NULL)
            return;
        TreeNode *lca = root;
        int pdist = 0;
        int qdist = 0;
        if (findItem(root, p->val, pdist) && findItem(root, q->val, qdist) && (pdist + qdist) <= lastDist)
        {
            lca = root;
        }
        findParent(root->left, p, q, (pdist + qdist));
        findParent(root->right, p, q, (pdist + qdist));
        root = lca;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        findParent(root, p, q, 100000);
        return root;
    }
};

// INFO:Working solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    bool findItem(TreeNode *root, int target)
    {
        if (root == NULL)
            return false;
        if (root->val == target)
            return true;
        return findItem(root->left, target) || findItem(root->right, target);
    };
    void findParent(TreeNode *&root, TreeNode *p, TreeNode *q, TreeNode *&currentroot)
    {
        if (currentroot == NULL)
            return;
        if (findItem(currentroot, p->val) && findItem(currentroot, q->val))
        {
            root = currentroot;
        }
        findParent(root, p, q, currentroot->left);
        findParent(root, p, q, currentroot->right);
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *&root, TreeNode *p, TreeNode *q)
    {
        findParent(root, p, q, root);
        return root;
    }
};

// INFO: Optimised Solution
class Solution
{
    /**
     * Helper function to check whether the subtree rooted at `current` contains the nodes `target1` and `target2`.
     * If it finds both nodes, it sets `lca` to the lowest common ancestor (LCA) of `target1` and `target2`.
     *
     * @param current The current node in the recursive traversal.
     * @param target1 The first target node we are looking for.
     * @param target2 The second target node we are looking for.
     * @param lca A reference to the node that will be set as the lowest common ancestor.
     * @return `true` if the subtree rooted at `current` contains at least one of the target nodes.
     */
    bool containsNodes(TreeNode *current, TreeNode *target1, TreeNode *target2, TreeNode *&lca)
    {
        // Base case: if the current node is null, it does not contain any target nodes.
        if (!current)
            return false;

        // Recursively check if the left subtree contains one or both of the target nodes.
        bool left = containsNodes(current->left, target1, target2, lca);

        // Recursively check if the right subtree contains one or both of the target nodes.
        bool right = containsNodes(current->right, target1, target2, lca);

        // Check if the current node itself is one of the target nodes.
        bool mid = (current == target1 || current == target2);

        // Determine if the current node is the lowest common ancestor:
        // If any two of the three conditions (left, right, mid) are true, then `current` is the LCA.
        if ((left && right) || (mid && (left || right)))
        {
            lca = current; // Update the LCA to the current node.
        }

        // Return `true` if the current subtree contains at least one of the target nodes.
        return left || right || mid;
    }

public:
    /**
     * Function to find the lowest common ancestor of two nodes `p` and `q` in a binary tree.
     *
     * @param root The root of the binary tree.
     * @param p The first node.
     * @param q The second node.
     * @return The lowest common ancestor (LCA) of `p` and `q`.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *lca = nullptr;        // Initialize the LCA as null.
        containsNodes(root, p, q, lca); // Start the recursive process to find the LCA.
        return lca;                     // Return the LCA found.
    }
};
