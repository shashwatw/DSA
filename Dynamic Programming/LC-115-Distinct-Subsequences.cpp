//* https://leetcode.com/problems/distinct-subsequences/description/

//^ ---------------------------------------------------MEMOIZATION----------------------------------------------------------

// MEMOIZATION

class Solution
{
private:
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        int MOD = 1e9 + 7;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
        {
            return dp[i][j] = (solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp)) % MOD;
        }

        return dp[i][j] = solve(i - 1, j, s, t, dp) % MOD;
    }

public:
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, s, t, dp);
    }
};

//^ ---------------------------------------------------TABULATION----------------------------------------------------------

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        int MOD = 1e9 + 7;

        vector<vector<int>> tab(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++)
        {
            tab[i][0] = 1;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    // here first one after = is when both last char match
                    //  Second one is for een though they match we check for any other
                    //  occurence of that charac in the string
                    tab[i][j] = (tab[i - 1][j - 1] + tab[i - 1][j]) % MOD;
                }
                else
                {
                    // If doesnt match move the string
                    tab[i][j] = tab[i - 1][j] % MOD;
                }
            }
        }
        return tab[m][n] % MOD;
    }
};