//* https://leetcode.com/problems/2-keys-keyboard/

class Solution
{
public:
    int minSteps(int n)
    {
        // Initialize a DP array to store the minimum steps to achieve each number of 'A's
        vector<int> dp(n + 1, 0);

        // Start from 2 because dp[1] is 0 (no operations needed to have one 'A')
        for (int i = 2; i <= n; i++)
        {
            dp[i] = i; // Maximum steps needed is 'i' (1 'Copy All' + i-1 'Paste')
            for (int j = i / 2; j >= 1; j--)
            {
                // If 'i' can be obtained by j*copies
                if (i % j == 0)
                {
                    dp[i] = dp[j] + (i / j); // i/j times is paste operations (1 copy and 2 paste for n = 9)
                    break;                   // The first factor found gives the optimal steps
                }
            }
        }

        return dp[n];
    }
};
https: // leetcode.com/problems/2-keys-keyboard/