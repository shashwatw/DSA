// https://leetcode.com/problems/smallest-string-starting-from-leaf/description/

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
public:
    string smallestString;

    string smallestFromLeaf(TreeNode *root)
    {
        dfs(root, "");
        return smallestString;
    }

    void dfs(TreeNode *root, string currentString)
    {
        if (root == NULL)
            return;

        currentString = char(root->val + 'a') + currentString;

        if (!root->left && !root->right)
        {
            if (smallestString.empty() || smallestString > currentString)
            {
                smallestString = currentString;
            }
        }

        dfs(root->left, currentString);
        dfs(root->right, currentString);

        // After processing the current node, remove the character to backtrack
        currentString.pop_back();
    }
};