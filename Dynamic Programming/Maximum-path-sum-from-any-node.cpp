//* https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
//^ Reference Video : https://www.youtube.com/watch?v=Osz-Vwer6rw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=48

// User Fuction template for C++

class Solution
{
private:
    int solve(Node *root, int &res)
    {
        if (root == nullptr)
            return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = max(max(l, r) + root->data, root->data);
        int ans = max(temp, l + r + root->data);
        res = max(res, ans);

        return temp;
    }

public:
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root)
    {
        // Your code goes here
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};