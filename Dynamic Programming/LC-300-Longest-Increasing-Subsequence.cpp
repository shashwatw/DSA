//* https://leetcode.com/problems/longest-increasing-subsequence/description/
//& Reference Video :    https://www.youtube.com/watch?v=ekcwMsSIzVc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=42
//& Tab & Most Optimal : https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=43

//* Intuition
//^ What we want is that the longest subsequence length that should be in increasing order
//^ Now at each value we have two options -> Take or not take
//^ We will follow same logic but here we will need another variable which will store the last value we stored so that we get to know that current variable is greater than the prev one or not
//^ By suitable logic we will return the max of both lengths

//*-------------------------------------RECURSIVE----------------------------------------

class Solution
{
private:
    int solve(int ind, int prev_ind, int n, vector<int> &nums)
    {
        // base case
        if (ind == n)
            return 0;

        int take = 0, notTake = 0;
        // if take the number
        if (prev_ind == -1 || nums[ind] > nums[prev_ind])
        {
            take = 1 + solve(ind + 1, ind, n, nums);
        }

        notTake = 0 + solve(ind + 1, prev_ind, n, nums);

        int len = max(take, notTake);
        return len;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return solve(0, -1, n, nums);
    }
};

//* -------------------------------------MEMOIZED----------------------------------------

class Solution
{
private:
    int solve(int ind, int prev_ind, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        // base case
        if (ind == n)
            return 0;

        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];

        int take = 0, notTake = 0;
        // if take the number
        if (prev_ind == -1 || nums[ind] > nums[prev_ind])
        {
            take = 1 + solve(ind + 1, ind, n, nums, dp);
        }

        notTake = 0 + solve(ind + 1, prev_ind, n, nums, dp);

        int len = max(take, notTake);
        return dp[ind][prev_ind + 1] = len;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, n, nums, dp);
    }
};

//* -------------------------------------TABULATION----------------------------------------

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> tab(n + 1, vector<int>(n + 1, 0));

        // base case no need as we initialised all to be 0
        // for(int j = 0; j <=n; j++)
        // {
        //     tab[n][j] = 0;
        // }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
            {
                int take = 0, notTake = 0;
                if (prev_ind == -1 || nums[ind] > nums[prev_ind])
                {
                    take = 1 + tab[ind + 1][ind + 1];
                }

                notTake = 0 + tab[ind + 1][prev_ind + 1];

                int len = max(take, notTake);
                tab[ind][prev_ind + 1] = len;
            }
        }
        return tab[0][0];
    }
};

//* -------------------------------------1D Space TABULATION---------------------------------

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ahead(n + 1, 0), curr(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
            {
                int take = 0, notTake = 0;
                if (prev_ind == -1 || nums[ind] > nums[prev_ind])
                {
                    take = 1 + ahead[ind + 1];
                }

                notTake = 0 + ahead[prev_ind + 1];

                int len = max(take, notTake);
                curr[prev_ind + 1] = len;
            }
            ahead = curr;
        }
        return ahead[0];
    }
};

// *********************************MOST OPTIMAL*****************************************

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxi = 1;
        for (int ind = 0; ind < n; ind++)
        {
            for (int prev_ind = 0; prev_ind < ind; prev_ind++)
            {
                if (nums[ind] > nums[prev_ind]) // can we take next index as value is greater
                {
                    dp[ind] = max(dp[ind], 1 + dp[prev_ind]);
                }
            }
            maxi = max(maxi, dp[ind]);
        }
        return maxi;
    }
};