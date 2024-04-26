//^ https://leetcode.com/problems/minimum-falling-path-sum-ii/

//* INTUITION :
//* First we made a copy of grid and copied first row of grid into new copy dp
//* Then we started a loop from 2nd row and checking each col
//* In each cell we check sum of above row and of all cell just not of the cell which has j nad k equal as it won't be a falling sum
//* Keep updating cell values like this
//* Now finally return the lowest value of last row in dp grid

//& Time Complexity = O(n^3)
//& Space Complexity = O(n^2)

//~ CODE:

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), res = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int j = 0; j < n; ++j)
        {
            dp[0][j] = grid[0][j];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int temp = INT_MAX;

                for (int k = 0; k < n; ++k)
                {
                    if (k != j)
                    {
                        temp = min(temp, grid[i][j] + dp[i - 1][k]);
                    }

                    dp[i][j] = temp;
                }
            }
        }

        for (int j = 0; j < n; ++j)
        {
            res = min(res, dp[n - 1][j]);
        }

        return res;
    }
};