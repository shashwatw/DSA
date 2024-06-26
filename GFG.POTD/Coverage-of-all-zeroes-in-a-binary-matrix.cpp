//* https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1

class Solution
{
public:
    int findCoverage(vector<vector<int>> &matrix)
    {
        // Code here
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int coverage = 0;
                if (matrix[i][j] == 0)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int nr = i + delRow[k];
                        int nc = j + delCol[k];

                        if (nr >= 0 && nr < row && nc >= 0 && nc < col && matrix[nr][nc] == 1)
                        {
                            coverage++;
                        }
                    }
                }
                ans += coverage;
            }
        }
        return ans;
    }
};