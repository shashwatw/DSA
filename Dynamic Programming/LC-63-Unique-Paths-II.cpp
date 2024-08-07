//*https://leetcode.com/problems/unique-paths-ii

//^ Path with obstacles

//* RECURSIVE
class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &obstacleGrid)
    {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
        {
            return 0;
        }

        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        int up = solve(i - 1, j, obstacleGrid);
        int left = solve(i, j - 1, obstacleGrid);

        return up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return solve(m - 1, n - 1, obstacleGrid);
    }
};

//* MEMOIZED
class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
        {
            return 0;
        }

        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = solve(i - 1, j, obstacleGrid, dp);
        int left = solve(i, j - 1, obstacleGrid, dp);

        return dp[i][j] = up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, obstacleGrid, dp);
    }
};
