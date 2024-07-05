//* https://www.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1

//^INTUITION
//* We will find out leftmost vertical and rightmost one and then subtract them to get final ans

class Solution
{
private:
    void solve(Node *node, int &leftmost, int &rightmost, int pos)
    {
        if (!node)
            return;

        leftmost = min(pos, leftmost);
        rightmost = max(pos, rightmost);

        if (node->left)
        {
            solve(node->left, leftmost, rightmost, pos - 1);
        }

        if (node->right)
        {
            solve(node->right, leftmost, rightmost, pos + 1);
        }
    }

public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node *root)
    {
        // code here
        if (root == NULL)
            return 0;

        int rightmost = 0;
        int leftmost = 0;

        solve(root, leftmost, rightmost, 0);
        return rightmost - leftmost + 1;
    }
};