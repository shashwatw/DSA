//* https://leetcode.com/problems/minimum-path-sum/description/

//^ -------------------------RECURSIVE APPROACH---------------------------------
class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &grid)
    {
        // Base cases
        if (i == 0 && j == 0)
            return grid[i][j];
        if (i < 0 || j < 0)
            return INT_MAX;

        // Calculate the minimum path sum for the cell above (if valid)
        int up = solve(i - 1, j, grid);
        // Calculate the minimum path sum for the cell to the left (if valid)
        int left = solve(i, j - 1, grid);

        // The minimum path sum to reach this cell is the current cell's value plus the minimum of the sums to reach the cells above and to the left
        return grid[i][j] + min(up, left);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        // Compute the minimum path sum from the bottom-right to the top-left
        return solve(m - 1, n - 1, grid);
    }
};

//^ -----------------------------------MEMOIZATION APPROACH------------------------------

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        // Base cases
        if (i == 0 && j == 0)
            return grid[i][j];
        if (i < 0 || j < 0)
            return INT_MAX;

        // If the result for this cell is already computed, return it
        if (dp[i][j] != -1)
            return dp[i][j];

        // Calculate the minimum path sum for the cell above (if valid)
        int up = solve(i - 1, j, grid, dp);
        // Calculate the minimum path sum for the cell to the left (if valid)
        int left = solve(i, j - 1, grid, dp);

        // The minimum path sum to reach this cell is the current cell's value plus the minimum of the sums to reach the cells above and to the left
        dp[i][j] = grid[i][j] + min(up, left);

        return dp[i][j];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        // Initialize a DP table with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // Compute the minimum path sum from the bottom-right to the top-left
        return solve(m - 1, n - 1, grid, dp);
    }
};
