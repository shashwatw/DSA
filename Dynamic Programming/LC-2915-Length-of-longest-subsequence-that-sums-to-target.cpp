//* https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/

class Solution
{
public:
    int lengthOfLongestSubsequence(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> lengths(n + 1, vector<int>(target + 1, -1));

        // Initialize lengths for sum 0
        for (int i = 0; i <= n; ++i)
        {
            lengths[i][0] = 0; // Sum of 0 can be achieved with an empty subsequence of length 0
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= target; ++j)
            {
                // If current element nums[i-1] is less than or equal to the target sum j
                if (nums[i - 1] <= j)
                {
                    if (lengths[i - 1][j - nums[i - 1]] != -1)
                    {
                        lengths[i][j] = max(lengths[i - 1][j], lengths[i - 1][j - nums[i - 1]] + 1);
                    }
                    else
                    {
                        lengths[i][j] = lengths[i - 1][j];
                    }
                }
                else
                {
                    lengths[i][j] = lengths[i - 1][j];
                }
            }
        }

        return lengths[n][target] == -1 ? -1 : lengths[n][target];
    }
};
