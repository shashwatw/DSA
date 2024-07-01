//* https://leetcode.com/problems/cherry-pickup-ii/description/
//^ Reference: https://www.youtube.com/watch?v=QGfn7JeXK54&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=14

//* ******************************************MEMOIZATION************************************************

class Solution
{
public:
    int m, n;
    int dp[71][71][71]; // a dp array for memoization...
    int helper(vector<vector<int>> &grid, int row, int column1, int column2)
    {
        if (row >= m)
            return 0; // base case...
        if (dp[row][column1][column2] != -1)
            return dp[row][column1]
                     [column2]; // if solution is already available in dp array
                                // then, return it...
        int cherryCount = grid[row][column1];
        if (column1 != column2)
            cherryCount += grid[row][column2]; // Take...
        int result = 0;
        for (int i = -1; i <= 1; ++i)
        { // for Robot 1...
            for (int j = -1; j <= 1; ++j)
            { // for Robot 2...
                int newRow = row + 1;
                int newColumn1 = column1 + i;
                int newColumn2 = column2 + j;
                if (newColumn1 >= 0 && newColumn1 < n && newColumn2 >= 0 &&
                    newColumn2 < n)
                    result = max(result,
                                 helper(grid, newRow, newColumn1, newColumn2));
            }
        }
        return dp[row][column1][column2] = cherryCount + result;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        m = grid.size();            // Total no. of rows...
        n = grid[0].size();         // Total no. of columns...
        memset(dp, -1, sizeof(dp)); // Initialization...
        return helper(grid, 0, 0, n - 1);
    }
};

//* *********************************************TABULATION*************************************************

//* TABULATION
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, 0)));

        // Initialize the base case: the bottom row of the grid
        for (int j1 = 0; j1 < n; ++j1)
        {
            for (int j2 = 0; j2 < n; ++j2)
            {
                if (j1 == j2)
                {
                    dp[m - 1][j1][j2] = grid[m - 1][j1];
                }
                else
                {
                    dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
                }
            }
        }

        // Fill the dp array from the bottom to the top
        for (int i = m - 2; i >= 0; --i)
        {
            for (int j1 = 0; j1 < n; ++j1)
            {
                for (int j2 = 0; j2 < n; ++j2)
                {
                    int maxCherries = 0;

                    // Consider all possible moves for both robots
                    for (int dj1 = -1; dj1 <= 1; ++dj1)
                    {
                        for (int dj2 = -1; dj2 <= 1; ++dj2)
                        {
                            int newJ1 = j1 + dj1;
                            int newJ2 = j2 + dj2;

                            if (newJ1 >= 0 && newJ1 < n && newJ2 >= 0 &&
                                newJ2 < n)
                            {
                                int currentCherries =
                                    (j1 == j2) ? grid[i][j1]
                                               : grid[i][j1] + grid[i][j2];
                                maxCherries = max(maxCherries,
                                                  currentCherries +
                                                      dp[i + 1][newJ1][newJ2]);
                            }
                        }
                    }

                    dp[i][j1][j2] = maxCherries;
                }
            }
        }

        return dp[0][0][n - 1];
    }
};