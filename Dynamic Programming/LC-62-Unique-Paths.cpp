//* https://leetcode.com/problems/unique-paths/

//^ INTUITION
//* We want to count unique paths
//* Now we know from any place in matrix we want to go to [0][0] place that is from destination we can only move left and up
//* So we consider once going up and once going left and finally sumup the answer
//* We wrote Base conditions as if it is start node then it is a path and if i or j is going out of matrix do not count as path

//^ -----------------------------------------RECURSIVE-------------------------------------------------
//& TC - O(2^(m*n)) SC - O(push length)

class Solution
{
private:
    int solve(int i, int j)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        int up = solve(i - 1, j);
        int left = solve(i, j - 1);

        return up + left;
    }

public:
    int uniquePaths(int m, int n)
    {

        return solve(m - 1, n - 1);
    }
};

//^ -----------------------------------------MEMOIZED-------------------------------------------------
//& TC - O(N*M) SC-O(N*M) + O((n-1) + (m-1)) --> recur stack space

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        int up, left;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i > 0)
        {
            if (dp[i - 1][j] != -1)
            {
                up = dp[i - 1][j];
            }
            else
            {
                up = solve(i - 1, j, dp);
                dp[i - 1][j] = up;
            }
        }
        else
        {
            up = 0; // If i == 0, there's no upward path
        }

        if (j > 0)
        {
            if (dp[i][j - 1] != -1)
            {
                left = dp[i][j - 1];
            }
            else
            {
                left = solve(i, j - 1, dp);
                dp[i][j - 1] = left;
            }
        }
        else
        {
            left = 0; // If j == 0, there's no leftward path
        }

        return dp[i][j] = up + left;
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }
};

//^ -----------------------------------------TABULATION-------------------------------------------------
//& TC - O(N*M) SC-O(N*M)

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> tab(m, vector<int>(n, 0));

        // Initialize the first row and first column
        for (int i = 0; i < m; ++i)
            tab[i][0] = 1;
        for (int j = 0; j < n; ++j)
            tab[0][j] = 1;

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                tab[i][j] = tab[i - 1][j] + tab[i][j - 1];
            }
        }
        return tab[m - 1][n - 1];
    }
};
