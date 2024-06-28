//* https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
private:
    int solve(TreeNode *root, int &res)
    {
        if (root == nullptr)
            return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int tempAns = max(max(l, r) + root->val,
                          root->val); // jab root apne aap ko consider nhi krra
        int ans = max(tempAns,
                      l + r + root->val); // jab root sirf khudko aur left right
                                          // ko leke max sum consider krra h

        res = max(res, ans);

        return tempAns;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};