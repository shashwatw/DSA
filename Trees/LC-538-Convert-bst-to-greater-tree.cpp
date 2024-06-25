//* https://leetcode.com/problems/convert-bst-to-greater-tree/

//* RECURSIVE APPROACH ------------------------------------------------------------

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
    TreeNode *convertBST(TreeNode *root)
    {
        solve(root);
        return root;
    }
};

//* Morris Traversal (iterative) APPROACH ------------------------------------------------------------ space->O(1)
//^ Refer : https://www.youtube.com/watch?v=9Aw18-yQs6o

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
    // Morris Traversal
    int globalSum;
    TreeNode *postExtremeLeftFunc(TreeNode *node)
    {
        TreeNode *post = node->right;
        while (post->left != NULL && post->left != node)
        {
            post = post->left;
        }
        return post;
    }

    TreeNode *convertBST(TreeNode *root)
    {
        globalSum = 0;
        TreeNode *node = root;

        while (node != NULL)
        {
            TreeNode *post = node->right;
            if (post == NULL)
            {
                globalSum += node->val;
                node->val = globalSum;
                node = node->left;
            }
            else
            {
                TreeNode *postExtremeLeft = postExtremeLeftFunc(node);

                if (postExtremeLeft->left == NULL)
                {
                    postExtremeLeft->left = node;
                    node = node->right;
                }
                else
                {
                    postExtremeLeft->left = NULL;
                    globalSum += node->val;
                    node->val = globalSum;
                    node = node->left;
                }
            }
        }
        return root;
    }
};