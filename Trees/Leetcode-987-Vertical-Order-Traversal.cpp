// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode *curr = it.first;
            int vertical = it.second.first;
            int lvl = it.second.second;

            mp[vertical][lvl].insert(curr->val);

            if (curr->left)
                q.push({curr->left, {vertical - 1, lvl + 1}});

            if (curr->right)
                q.push({curr->right, {vertical + 1, lvl + 1}});
        }

        vector<vector<int>> ans;
        for (auto n : mp)
        {
            vector<int> col;
            for (auto c : n.second)
            {
                col.insert(col.end(), c.second.begin(), c.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};