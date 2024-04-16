// https://leetcode.com/problems/add-one-row-to-tree/description/

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
    TreeNode *addDepth(TreeNode *root, int val, int depth, int level)
    {
        if (root == NULL)
            return root;

        if (level + 1 == depth)
        {
            TreeNode *l = new TreeNode(val);
            l->left = root->left;
            root->left = l;

            TreeNode *r = new TreeNode(val);
            r->right = root->right;
            root->right = r;

            return root;
        }

        root->left = addDepth(root->left, val, depth, level + 1);
        root->right = addDepth(root->right, val, depth, level + 1);

        return root;
    }

    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *curr = new TreeNode(val);
            curr->left = root;
            return curr;
        }
        addDepth(root, val, depth, 1);
        return root;
    }
};
