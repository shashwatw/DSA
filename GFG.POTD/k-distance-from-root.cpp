//^ https://www.geeksforgeeks.org/problems/k-distance-from-root/1

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution
{
public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
        // Your code here
        vector<int> res;
        if (root == NULL)
            return res;

        if (k == 0)
        {
            res.push_back(root->data);
            return res;
        }

        // Traverse left subtree with k decremented by 1
        vector<int> left = Kdistance(root->left, k - 1);
        for (int node : left)
        {
            res.push_back(node);
        }

        // Traverse right subtree with k decremented by 1
        vector<int> right = Kdistance(root->right, k - 1);
        for (int node : right)
        {
            res.push_back(node);
        }

        return res;
    }
};