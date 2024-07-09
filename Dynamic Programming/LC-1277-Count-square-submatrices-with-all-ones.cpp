//* https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
//^ Reference Video : https://www.youtube.com/watch?v=auS1fynpnjo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=57

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));
        int totalSquares = 0;

        // Initialize the first row and first column of dp
        for (int i = 0; i < row; i++)
        {
            dp[i][0] = matrix[i][0];
            totalSquares += dp[i][0];
        }

        for (int j = 1; j < col; j++)
        {
            dp[0][j] = matrix[0][j];
            totalSquares += dp[0][j];
        }

        // Fill the dp matrix
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (matrix[i][j] == 1)
                {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    totalSquares += dp[i][j];
                }
            }
        }

        return totalSquares;
    }
};
