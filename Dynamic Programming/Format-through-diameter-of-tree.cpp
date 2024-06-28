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

//! return res;
//! }

// int main()
// {
//     string res;
//     return solve(root, res);
// }