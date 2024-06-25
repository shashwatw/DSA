//* https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

//^ RECURSIVE APPROACH O(n)-time and O(n)-space

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
    int grs = 0; // greater right sum
private:
    void solve(TreeNode *node)
    {
        if (node == NULL)
            return;

        solve(node->right);
        grs += node->val;
        node->val = grs;
        solve(node->left);
    }

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        solve(root);
        return root;
    }
};