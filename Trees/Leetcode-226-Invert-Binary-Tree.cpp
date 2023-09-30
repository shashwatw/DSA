// https://leetcode.com/problems/invert-binary-tree

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
    void traversal(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        traversal(root->left);
        traversal(root->right);
    }

    TreeNode *invertTree(TreeNode *root)
    {
        traversal(root);
        return root;
    }
};