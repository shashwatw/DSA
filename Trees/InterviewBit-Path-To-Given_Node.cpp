// https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void sol(TreeNode *A, int B, vector<int> &v)
{
    if (!A)
        return;
    if (A->val == B)
    {
        v.push_back(A->val);
        return;
    }
    sol(A->left, B, v);
    if (v.size() > 0)
    {
        v.push_back(A->val);
        return;
    }
    sol(A->right, B, v);
    if (v.size() > 0)
    {
        v.push_back(A->val);
        return;
    }
    return;
}

vector<int> Solution::solve(TreeNode *A, int B)
{
    vector<int> v;
    sol(A, B, v);
    reverse(v.begin(), v.end());
    return v;
}
