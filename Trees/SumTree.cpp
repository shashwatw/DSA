//* https://www.geeksforgeeks.org/problems/sum-tree/1

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
private:
    int solve(Node *node)
    {
        if (node == NULL)
            return 0;

        int sum = node->data + solve(node->left) + solve(node->right);
        return sum;
    }

public:
    bool isSumTree(Node *root)
    {
        // Your code here
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return true;
        }

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        if (root->data == leftSum + rightSum)
        {
            return isSumTree(root->left) && isSumTree(root->right);
        }
        else
        {
            return false;
        }
    }
};