//* https://leetcode.com/problems/rotate-image/description/

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = i + 1; j < col; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse each row of matrix
        for (int rows = 0; rows < row; rows++)
        {
            for (int cols = 0; cols < col / 2; cols++)
            {
                swap(matrix[rows][cols], matrix[rows][col - cols - 1]);
            }
        }
    }
};