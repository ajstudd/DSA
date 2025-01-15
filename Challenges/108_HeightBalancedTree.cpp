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
    TreeNode *sortedArrayToBSTHelper(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr; // Base case: no elements to process
        }

        int mid = left + (right - left) / 2;      // Find the middle element
        TreeNode *root = new TreeNode(nums[mid]); // Create a node with the middle element

        // Recursively construct the left and right subtrees
        root->left = sortedArrayToBSTHelper(nums, left, mid - 1);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, right);

        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
};
