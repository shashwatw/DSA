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