//* https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution
{
public:
    bool hasPathSum(Node *root, int target)
    {
        // Your code here
        if (root == NULL)
            return false;

        target -= root->data;
        if (root->left == NULL && root->right == NULL && target == 0)
            return true;

        return hasPathSum(root->left, target) || hasPathSum(root->right, target);
    }
};