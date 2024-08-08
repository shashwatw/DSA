//* https://leetcode.com/problems/spiral-matrix-iii/

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart)
    {
        vector<vector<int>> result;
        int total = rows * cols;
        // result.push_back({rStart, cStart});

        int startingRow = rStart;
        int startingCol = cStart;

        int step = 1;

        while (result.size() < total)
        {
            // Move right
            for (int i = 0; i < step; ++i)
            {
                if (startingCol >= 0 && startingCol < cols &&
                    startingRow >= 0 && startingRow < rows)
                {
                    result.push_back({startingRow, startingCol});
                }
                startingCol++;
            }

            // Move down
            for (int i = 0; i < step; ++i)
            {
                if (startingCol >= 0 && startingCol < cols &&
                    startingRow >= 0 && startingRow < rows)
                {
                    result.push_back({startingRow, startingCol});
                }
                startingRow++;
            }

            // Increment the step again after another two direction changes
            // (left & up)
            step++;

            // Move left
            for (int i = 0; i < step; ++i)
            {
                if (startingCol >= 0 && startingCol < cols &&
                    startingRow >= 0 && startingRow < rows)
                {
                    result.push_back({startingRow, startingCol});
                }
                startingCol--;
            }

            // Move up
            for (int i = 0; i < step; ++i)
            {
                if (startingCol >= 0 && startingCol < cols &&
                    startingRow >= 0 && startingRow < rows)
                {
                    result.push_back({startingRow, startingCol});
                }
                startingRow--;
            }
            step++;
        }

        return result;
    }
};
