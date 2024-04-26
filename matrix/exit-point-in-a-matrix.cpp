//^ https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1

class Solution
{
public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>> &matrix)
    {
        // Initialize variables
        int row = 0, col = 0;
        vector<int> exitPoint;

        // Define directions: right, down, left, up
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0; // Start with "right" direction

        while (row >= 0 && row < n && col >= 0 && col < m)
        {
            if (matrix[row][col] == 1)
            {
                // Change direction to the right of the current direction
                dir = (dir + 1) % 4;
                // Change the value of the current cell to 0
                matrix[row][col] = 0;
            }

            // Move to the next cell in the current direction
            row += dirs[dir][0];
            col += dirs[dir][1];
        }

        // Exit point is the current position
        exitPoint.push_back(row - dirs[dir][0]);
        exitPoint.push_back(col - dirs[dir][1]);
        return exitPoint;
    }
};