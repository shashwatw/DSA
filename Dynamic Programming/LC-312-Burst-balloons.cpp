//* https://leetcode.com/problems/burst-balloons/
//& Reference Video : https://www.youtube.com/watch?v=Yz4LlDSlkns&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=52

//* INTUITION
//^ It was yet another MCM problem where we identified it as we can do any where partitioning
//^ This problem is a variation where we have to perform MCM in reverse order...i.e. the balloon that is burst we assume that is the last baloon to be burst and hence it will be present in all prev case
//^ That's how we are having track of the burst balloon and balloon to its right and left...watch video for better clarification as it's complex logic

//* *******************************RECURSIVE******************************************

class Solution
{
private:
    int solve(vector<int> &nums, int i, int j)
    {
        if (i > j)
            return 0;

        int maxi = INT_MIN;
        for (int ind = i; ind <= j; ind++)
        {
            int cost = nums[i - 1] * nums[ind] * nums[j + 1] +
                       solve(nums, i, ind - 1) + solve(nums, ind + 1, j);
            maxi = max(maxi, cost);
        }
        return maxi;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        return solve(nums, 1, n - 2);
    }
};

//* *******************************MEMOIZED******************************************

class Solution
{
private:
    int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = INT_MIN;
        for (int ind = i; ind <= j; ind++)
        {
            int cost = nums[i - 1] * nums[ind] * nums[j + 1] +
                       solve(nums, i, ind - 1, dp) + solve(nums, ind + 1, j, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(nums, 1, n - 2, dp);
    }
};