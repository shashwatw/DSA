// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

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
    int findMaxDistance(map<TreeNode *, TreeNode *> mpp, TreeNode *target)
    {
        queue<TreeNode *> q;
        map<TreeNode *, int> visited;
        q.push(target);
        int maxi = 0;
        visited[target] = 1;
        int fl = 0;

        while (!q.empty())
        {
            int size = q.size();
            fl = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left])
                {
                    fl = 1;
                    q.push(curr->left);
                    visited[curr->left] = 1;
                }

                if (curr->right && !visited[curr->right])
                {
                    fl = 1;
                    q.push(curr->right);
                    visited[curr->right] = 1;
                }

                if (mpp[curr] && !visited[mpp[curr]])
                {
                    fl = 1;
                    q.push(mpp[curr]);
                    visited[mpp[curr]] = 1;
                }
            }
            if (fl == 1)
                maxi++;
        }
        return maxi;
    }

    TreeNode *bfsToMapParents(TreeNode *root, map<TreeNode *, TreeNode *> &mpp, int start)
    {
        queue<TreeNode *> q;
        q.push(root);

        TreeNode *res = 0;

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->val == start)
                res = curr;

            if (curr->left)
            {
                mpp[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                mpp[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return res;
    }

    int amountOfTime(TreeNode *root, int start)
    {
        map<TreeNode *, TreeNode *> mpp;
        TreeNode *target = bfsToMapParents(root, mpp, start);
        int maxi = findMaxDistance(mpp, target);
        return maxi;
    }
};