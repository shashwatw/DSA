//^ https://leetcode.com/problems/create-binary-tree-from-descriptions/

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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_set<int> children, parents;
        unordered_map<int, vector<pair<int, int>>> parentToChildren;

        for (auto desc : descriptions)
        {
            int parent = desc[0], child = desc[1], isLeft = desc[2];
            parents.insert(parent);
            parents.insert(child);
            children.insert(child);
            parentToChildren[parent].emplace_back(child, isLeft);
        }

        for (auto it = parents.begin(); it != parents.end();)
        {
            if (children.find(*it) != children.end())
            {
                it = parents.erase(it);
            }
            else
            {
                ++it;
            }
        }
        TreeNode *root = new TreeNode(*parents.begin());

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *parent = q.front();
            q.pop();

            for (auto childInfo : parentToChildren[parent->val])
            {
                int childVal = childInfo.first, isLeft = childInfo.second;

                TreeNode *child = new TreeNode(childVal);
                q.push(child);

                if (isLeft == 1)
                {
                    parent->left = child;
                }
                else
                {
                    parent->right = child;
                }
            }
        }
        return root;
    }
};