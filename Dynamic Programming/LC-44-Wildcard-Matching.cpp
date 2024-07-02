//* https://leetcode.com/problems/wildcard-matching/description/

//^ ***************************************************MEMOIZATION*******************************************************

class Solution
{
private:
    // Memoization table
    vector<vector<int>> memo;

    bool solve(int i, int j, string &s, string &p)
    {
        // Base cases
        if (i < 0 && j < 0)
            return true; // Both strings finished
        if (i < 0 && j >= 0)
            return false; // Pattern finished, string didn't
        if (j < 0 && i >= 0)
        { // String finished, pattern didn't
            // Check remaining characters in the pattern
            for (int k = 0; k <= i; ++k)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        // Check memoization table
        if (memo[i][j] != -1)
            return memo[i][j];

        // If characters match or pattern has '?'
        if (p[i] == s[j] || p[i] == '?')
        {
            return memo[i][j] = solve(i - 1, j - 1, s, p);
        }

        // If pattern has '*'
        if (p[i] == '*')
        {
            return memo[i][j] = solve(i - 1, j, s, p) || solve(i, j - 1, s, p);
        }

        // No match
        return memo[i][j] = false;
    }

public:
    bool isMatch(string s, string p)
    {
        int m = p.size();
        int n = s.size();

        // Initialize memoization table with -1
        memo = vector<vector<int>>(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, s, p);
    }
};

//^ *****************************************TABULATION*************************************************************

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();

        // Create a table to store results of subproblems
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Empty pattern matches empty string
        dp[0][0] = true;

        // Handling patterns that start with '*'
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the table in bottom-up manner
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // If current characters match or pattern has '?', move diagonally
                if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    // If current pattern character is '*', check if it can match
                    // either by ignoring it ('*' matches empty sequence) or by
                    // matching one or more characters from string 's'
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        // Return the result for the full length of string and pattern
        return dp[m][n];
    }
};
