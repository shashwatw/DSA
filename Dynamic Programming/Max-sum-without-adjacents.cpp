//* https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

// User function template for C++
class Solution
{
private:
    int solve(int *arr, int ind, vector<int> &dp)
    {
        if (ind < 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        int pick = arr[ind] + solve(arr, ind - 2, dp);
        int notPick = 0 + solve(arr, ind - 1, dp);

        return dp[ind] = max(pick, notPick);
    }

public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        // code here
        vector<int> dp(n, -1);
        return solve(arr, n - 1, dp);
    }
};