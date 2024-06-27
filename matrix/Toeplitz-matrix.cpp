//* https://www.geeksforgeeks.org/problems/toeplitz-matrix/1

bool isToepliz(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();

    // Check all diagonals starting from the first row
    for (int i = 0; i < col; i++)
    {
        int value = mat[0][i];
        for (int r = 1, c = i + 1; r < row && c < col; r++, c++)
        {
            if (mat[r][c] != value)
            {
                return false;
            }
        }
    }

    // Check all diagonals starting from the first column
    for (int i = 1; i < row; i++)
    {
        int value = mat[i][0];
        for (int r = i + 1, c = 1; r < row && c < col; r++, c++)
        {
            if (mat[r][c] != value)
            {
                return false;
            }
        }
    }

    return true;
}