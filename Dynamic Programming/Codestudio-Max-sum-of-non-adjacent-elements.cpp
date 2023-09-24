// https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>

int solveMem(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    // Change 1: Add dp[n] to the recursive call
    int incl = solveMem(nums, n - 2, dp) + nums[n];
    int excl = solveMem(nums, n - 1, dp) + 0;

    dp[n] = max(incl, excl);

    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solveMem(nums, n - 1, dp);
}