// https://leetcode.com/problems/island-perimeter/description/

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        // bfs - when single land is there ( TC - row*col)
        // dfs - when multiple land is there ( here if applied TC - 4^(row*col))

        int n = grid.size();    // row
        int m = grid[0].size(); // col
        int cnt = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (grid[row][col] == 1)
                {
                    // up
                    if (row > 0 && grid[row - 1][col] == 0 || row == 0)
                    {
                        cnt++;
                    }

                    // down
                    if (row < n - 1 && grid[row + 1][col] == 0 || row == n - 1)
                    {
                        cnt++;
                    }

                    // left
                    if (col > 0 && grid[row][col - 1] == 0 || col == 0)
                    {
                        cnt++;
                    }

                    // right
                    if (col < m - 1 && grid[row][col + 1] == 0 || col == m - 1)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};