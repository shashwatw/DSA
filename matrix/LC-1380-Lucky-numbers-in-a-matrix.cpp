//* https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/

class Solution
{
private:
    void checkMax(vector<vector<int>> &matrix, int &mini, vector<int> &res, int &col)
    {
        int row = matrix.size();
        int maxi = INT_MIN;

        for (int i = 0; i < row; i++)
        {
            if (matrix[i][col] > maxi)
            {
                maxi = matrix[i][col];
            }
        }

        if (maxi == mini)
            res.push_back(mini);
    }

public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> res;

        int row = matrix.size();
        int col = matrix[0].size();
        int mini = INT_MAX;
        int currCol;

        for (int i = 0; i < row; i++)
        {
            mini = INT_MAX;
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] < mini)
                {
                    mini = matrix[i][j];
                    currCol = j;
                }
            }
            checkMax(matrix, mini, res, currCol);
        }
        return res;
    }
};