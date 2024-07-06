//* https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
//& Reference Video : https://www.youtube.com/watch?v=cKVl1TFdNXg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=48

//^ INTUITION
//* Basically here we want to find out frequency or number of unique LIS
//* So we will create a cnt array which increments in case of same length LIS or copies cnt of longer Inc Subsequence found
//* Below is code of it which has very subtle changes

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);

        int maxi = 1;

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[prev] < nums[i] && dp[prev] + 1 > dp[i])
                {
                    dp[i] = dp[prev] + 1;

                    // in that case inherit value from prev
                    cnt[i] = cnt[prev];
                }
                else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i])
                {
                    // increase the count
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int freq = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
            {
                freq += cnt[i];
            }
        }
        return freq;
    }
};