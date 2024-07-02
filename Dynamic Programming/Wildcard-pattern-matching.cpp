//* https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1

//^ TABULATION

class Solution
{
public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str)
    {
        int m = str.size();
        int n = pattern.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= n; ++j)
        {
            if (pattern[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pattern[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};