//* https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/
//* Check Bitonic Sequence first

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();

        // Longest Increasing Subsequence (LIS) from the front
        vector<int> dp1(n, 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j] && dp1[i] < dp1[j] + 1)
                {
                    dp1[i] = dp1[j] + 1;
                }
            }
        }

        // Longest Increasing Subsequence (LIS) from the back
        vector<int> dp2(n, 1);
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = n - 1; j > i; --j)
            {
                if (nums[i] > nums[j] && dp2[i] < dp2[j] + 1)
                {
                    dp2[i] = dp2[j] + 1;
                }
            }
        }

        // Find the maximum length of a bitonic subsequence
        int max_bitonic_length = 0;
        for (int i = 1; i < n - 1;
             ++i)
        { // The peak cannot be the first or the last element
            if (dp1[i] > 1 &&
                dp2[i] > 1)
            { // To be a peak, it should have LIS on both sides
                max_bitonic_length =
                    max(max_bitonic_length, dp1[i] + dp2[i] - 1);
            }
        }

        // Minimum removals to form a mountain array
        return n - max_bitonic_length;
    }
};
