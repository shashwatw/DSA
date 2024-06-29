//* https://leetcode.com/problems/house-robber-ii/

class Solution
{
public:
    int robLinear(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0; // No houses to rob
        if (n == 1)
            return nums[0]; // Only one house to rob

        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
            {
                take += dp[i - 2];
            }
            int notTake = dp[i - 1];

            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0]; // Only one house to rob

        // Rob houses from index 0 to n-2
        vector<int> nums1(nums.begin(), nums.end() - 1);
        int rob1 = robLinear(nums1);

        // Rob houses from index 1 to n-1
        vector<int> nums2(nums.begin() + 1, nums.end());
        int rob2 = robLinear(nums2);

        // Return the maximum of the two scenarios
        return max(rob1, rob2);
    }
};
