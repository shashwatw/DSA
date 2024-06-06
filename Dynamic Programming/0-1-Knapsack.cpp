//*https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

//^ APPROACH 1 - RECURSION
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        if (n == 0 || W == 0)
            return 0; // base condition

        if (wt[n - 1] <= W)
        {
            return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
        }
        else if (wt[n - 1] > W)
        {
            return knapSack(W, wt, val, n - 1);
        }
    }
};

//^ APPROACH 2 - MEMOIZATION
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        return knapSackHelper(W, wt, val, n, dp);
    }

    int knapSackHelper(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        // Your code here
        //^ APPROACH 2 : MEMOIZATION SOLUTION
        if (n == 0 || W == 0)
            return 0; // base condition

        if (dp[n][W] != -1)
            return dp[n][W];

        if (wt[n - 1] <= W)
        {
            return dp[n][W] = max(val[n - 1] + knapSackHelper(W - wt[n - 1], wt, val, n - 1, dp),
                                  knapSackHelper(W, wt, val, n - 1, dp));
        }
        else
        {
            return dp[n][W] = knapSackHelper(W, wt, val, n - 1, dp);
        }
    }
};