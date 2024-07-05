//* https://leetcode.com/problems/largest-divisible-subset/description/
//* Refer Print LIS Github first

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;

            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]) // just this condition changed from printing lIS
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev; // concept of backtracking
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);

        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};