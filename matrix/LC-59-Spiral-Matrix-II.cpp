//* https://leetcode.com/problems/spiral-matrix-ii/description/

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = n - 1;
        int endingCol = n - 1;
        int total = n * n;
        int num = 1;

        while (num <= total)
        {
            for (int col = startingCol; col <= endingCol && num <= total; col++)
            {
                matrix[startingRow][col] = num++;
            }
            startingRow++;

            for (int row = startingRow; row <= endingRow && num <= total; row++)
            {
                matrix[row][endingCol] = num++;
            }
            endingCol--;

            for (int col = endingCol; col >= startingCol && num <= total; col--)
            {
                matrix[endingRow][col] = num++;
            }
            endingRow--;

            for (int row = endingCol; row >= startingRow && num <= total; row--)
            {
                matrix[row][startingCol] = num++;
            }
            startingCol++;
        }
        return matrix;
    }
};