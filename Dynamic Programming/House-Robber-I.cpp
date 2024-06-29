//*https://leetcode.com/problems/house-robber/

//^ -------------------------------RECURSIVE------------------------------------------------
// & TC - O(n)

class Solution
{
private:
    int solve(vector<int> &nums, int ind)
    {
        if (ind < 0)
            return 0; // Base case for negative index

        // Recurrence relation: either pick the current house or don't
        int pick = nums[ind] + solve(nums, ind - 2);
        int notPick = solve(nums, ind - 1);

        // Return the maximum of picking or not picking the current house
        return max(pick, notPick);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        return solve(nums, n - 1); // Start solving from the last house
    }
};

//^ -------------------------------MEMOIZED------------------------------------------------

class Solution
{

private:
    int solve(vector<int> &nums, int ind, vector<int> &dp)
    {
        if (ind < 0)
            return 0; // Base case for negative index
        if (dp[ind] != -1)
            return dp[ind];

        int pick = nums[ind] + solve(nums, ind - 2, dp);
        int notPick = 0 + solve(nums, ind - 1, dp);

        // Return the maximum of picking or not picking the current house
        return dp[ind] = max(pick, notPick);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n - 1, dp); // Start solving from the last house
    }
};
