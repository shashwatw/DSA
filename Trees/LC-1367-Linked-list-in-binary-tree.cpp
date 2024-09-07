//* https://leetcode.com/problems/linked-list-in-binary-tree/description/

class Solution
{
private:
    bool solve(ListNode *node, TreeNode *root)
    {
        if (node == nullptr)
        {
            return true;
        }
        if (root == nullptr)
        {
            return false;
        }

        if (node->val == root->val)
        {
            return solve(node->next, root->left) ||
                   solve(node->next, root->right);
        }

        return false;
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (root == nullptr)
        {
            return false;
        }

        return solve(head, root) || isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }
};
