//! 4 Steps are present in any this type of question

// Below are the color codes or by ^ / * / &
//^ 1. Base Condition
//* 2. Hypothesis -- > never ques hypothesis
//& 3. Induction

//! Base Syntax taking diam of tree as example

//! int solve(Node *root, int &res) // very ump to pass res by reference as it will contain final ans
//! {
//^ if (root == nullptr)
//^     return 0;

//* int l = solve(root->left, res);
//* int r = solve(root->right, res);

//& int temp = 1 + max(l, r);
// calculate temp ans if we are not considering root in the longest path then longest of both l or r + 1 (of root) will be the temp height/dia to pass
//& int ans = max(temp, (1 + l + r)); // it can contain any relation
//& res = max(res, ans);

//! return temp;
//! }

// int main()
// {
//     int res;
//     return solve(root, res);
// }

//* ----------------- CODE ---------------------------------------

//^ https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1

/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution
{
private:
    int solve(Node *root, int &res)
    {
        if (root == nullptr)
            return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = 1 + max(l, r);
        int ans = max(temp, l + r + 1);
        res = max(res, ans);

        return temp;
    }

public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        // Your code here
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};